/*	Problem Statement: write a program to create and open a binary file with some value.
 *	Let it increment the value 500 times and enter the following values in the log file
 *	every time it's incremented: timestamp | pid | read_value | write_value.
 *  Use random sleep to avoid collison while reading the value from file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main() {
	FILE * binfile;
	FILE * logfile;

	//creates test.bin if doesn, exist
	if(access("test.bin", F_OK)) {
		binfile = fopen("test.bin", "wb+");
	}
	else {
		binfile = fopen("test.bin", "rb+");
	}
	
	logfile = fopen("log.txt", "a");

	pid_t pid = getpid();
	time_t TIME = time(NULL);
	struct tm tm = *localtime(&TIME);

	int val = 0, i = 0;

	//seeding the rand() function with the current systime
	srand(time(0));

	//seeting program to sleep for a random no between 1 to 10 sec
	sleep((rand()%(10-1))+2);

	fread(&val, 1, sizeof(binfile), binfile);

	for(i = 0; i < 500; i++) {
		val += 1;
		fwrite(&val, sizeof(int), 1, binfile);
		fprintf(logfile,"PID:%d time:%02d:%02d:%02d val:%d\n", pid, tm.tm_hour, tm.tm_min, tm.tm_sec, val);
		rewind(binfile);
	}
}