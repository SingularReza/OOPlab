#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>

void error(char * msg) {
  perror(msg);
  exit(1);
}

char *fileList(char * dirPath, int n) {
  DIR *d;
  struct dirent *dir;
  int i = 0, j = 0;
  char temp[n];

  for(i = 0; dirPath[i]!='\n'; i++) {
  	temp[i] = dirPath[i];
  }
  temp[n-1] = '\0';

  d = opendir(temp);
  char * list = (char *)malloc(1024 * sizeof(char));
  i = 0;

  if(d) {
    while((dir = readdir(d))!=NULL) {
      printf("%s\n", dir->d_name);
      if(i+strlen(dir->d_name) < 1024) {
      	for(j = 0; dir->d_name[j]!='\0';j++) {
	      	list[i] = dir->d_name[j];
	 		i++;
	    }
	    j = 0;
	    list[i] = ',';
	    i++;
	  }
	  else {
	  	break;
	  }
    }
    closedir(d);
  }
  else {
  	bzero(list, 1024);
  }

  return (char *)list;
}

int main(int argc, char ** argv) {
  int sockfd, portno, clientlen;
  struct sockaddr_in serveraddr, clientaddr;
  struct hostent *hostp;
  char buf[1024];
  char *hostaddrp;
  int optval;
  int n;

  if(argc!=2) {
    printf("wrong no of arguments");
    exit(1);
  }

  portno = atoi(argv[1]);

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockfd < 0) {
    error("ERROR opening socket");
  }

  optval = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void*)&optval, sizeof(int));

  bzero((char *)&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons((unsigned short)portno);

  if(bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr))<0) {
    error("ERROR on binding");
  }

  clientlen = sizeof(clientaddr);

  while(1) {
    bzero(buf, 1024);
    n = recvfrom(sockfd, buf, 1024, 0, (struct sockaddr *)&clientaddr, &clientlen);
    if(n < 0) {
      error("ERROR in recvfrom");
    }

    hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    if(hostp==NULL) {
      error("ERROR on gethostbyaddr");
    }

     hostaddrp = inet_ntoa(clientaddr.sin_addr);
     if(hostaddrp == NULL) {
      error("ERROR on inet_ntoa\n"); 
     }

    printf("server recieved datagram from %s (%s)\n", hostp->h_name, hostaddrp);
    printf("server recieved %d/%d bytes: %s\n", strlen(buf), n, buf);

    printf("%s\n", fileList(buf, n));
    char * temp = fileList(buf, n);

    n = sendto(sockfd, temp, strlen(temp), 0, (struct sockaddr *)&clientaddr, clientlen);
    printf("sent %d bytes\n", n);
    if(n < 0) {
      error("ERROR in sendto");
    }
  }
}
