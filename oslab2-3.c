#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	FILE * logfile;

	int process_count= 0;

	printf("Enter the no of child processes: ");
	scanf("%d", &process_count);

	while(process_count) {
		
		int pid = getpid();

		if(pid%2 && pid%5) {
			printf("mod 1");
			if(fork()) {
				logfile = fopen("childlog.txt", "a");
				fprintf(logfile,"PID:%d PPID:%d\n", pid, getppid());
				fclose(logfile);
				break;
			} else {
				process_count--;
				continue;
			}
		} else if(pid%5) {
			printf("mod 2");
			if(fork()) {
				if(fork()) {
					logfile = fopen("childlog.txt", "a");
					fprintf(logfile,"PID:%d PPID:%d\n", pid, getppid());
					fclose(logfile);
					break;
				} else {
					process_count--;
					continue;
				}
			} else {
				process_count--;
				continue;
			}
		} else {
			printf("mod 0");
			logfile = fopen("childlog.txt", "a");
			fprintf(logfile,"PID:%d PPID:%d\n", pid, getppid());
			fclose(logfile);
			break;
		}
	}
}