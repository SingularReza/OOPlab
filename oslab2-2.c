#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	FILE * logfile;

	int process_count= 0, test = 0;

	printf("Enter the no of child processes: ");
	scanf("%d", &process_count);

	while(process_count) {
		int pid = fork();

		if(pid) {
			if(pid%2) {
				printf("Hello \n");
			} 
			else {
				printf("World \n");
			}
			break;
		} else {
			logfile = fopen("childlog.txt", "a");
			fprintf(logfile,"PID:%d PPID:%d pid:%d test:%d\n", getpid(), getppid(), pid, test++);
			fclose(logfile);
			process_count--;
		}
	}

	return 0;
}