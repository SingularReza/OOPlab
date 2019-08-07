#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	FILE * logfile;
	logfile = fopen("childlog.txt", "a");

	int process_count= 0;

	printf("Enter the no of child processes: ");
	scanf("%d", &process_count);

	while(process_count) {
		int pid = fork();

		if(!pid) {
			//printf("test: %d %d \n", getpid(), pid);
			fprintf(logfile,"PID:%d PPID:%d pid:%d\n", getpid(), getppid(), pid);
			//printf("oof\n");
			process_count--;
		} else {
			if(pid%2) {
				printf("Hello \n");
			} else {
				printf("World \n");
			}
			break;
		}
	}
}