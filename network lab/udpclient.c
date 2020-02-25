#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void error(char * msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char ** argv) {
  int sockfd, portno, serverlen;
  struct sockaddr_in serveraddr;
  struct hostent *server;
  char buf[1024];
  char *hostname;
  //int optval;
  int n;

  if(argc!=3) {
    printf("wrong number of arguments");
    exit(1);
  }

	//printf("not used argumnets yet\n");
	hostname = argv[1];
  portno = atoi(argv[2]);
	//printf("used argumnets\n");

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockfd < 0) {
    error("ERROR opening socket");
  }

 	server = gethostbyname(hostname);
	if(server==NULL) {
		printf("no such server");
		exit(0);
	}
	
  bzero((char *)&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
  serveraddr.sin_port = htons((unsigned short)portno);

  //clientlen = sizeof(clientaddr);

    bzero(buf, 1024);
		printf("please enter message: ");
		fgets(buf, 1024, stdin);

		serverlen = sizeof(serveraddr);

		n = sendto(sockfd, buf, strlen(buf), 0, &serveraddr, serverlen);
    if(n < 0) {
      error("ERROR in sendto");
    }
		
    n = recvfrom(sockfd, buf, strlen(buf), 0, &serveraddr, &serverlen);
    if(n < 0) {
      error("ERROR in recvfrom");
    }

   	printf("reply from server: %s", buf);
		return 0;
}
