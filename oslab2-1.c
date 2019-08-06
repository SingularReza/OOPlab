#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	int process_count = 0;
	pid_t parent_pid = getpid();

	printf("Enter the no of child processes: ");
	scanf("%d", &process_count);

	for(; process_count>0; process_count--) {
		if(getpid() == parent_pid) {
			int child_pid = fork();
			if(child_pid) {
				if(!(child_pid%2)) {
					printf("Hello \n");
				} else {
					printf("World \n");
				}
			}
		}
		else {
			break;
		}
	}

	if(getpid()==parent_pid) {
			printf("Bye ");
	}
}