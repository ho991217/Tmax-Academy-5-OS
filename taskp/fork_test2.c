#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int glob = 6;
char buf[] = "a write to stdout\n";

int main() {
	int var = 88;
	pid_t fork_return;
	
	if (write(STDOUT_FILENO, buf, sizeof(buf) != sizeof(buf))) {
		perror("write error");
		exit(1);
	}
	printf("before fork\n");
	if ((fork_return = fork()) < 0) {
		perror("fork error");
		exit(1);
	} 
	else if (fork_return == 0) {
		glob++;
		var++;
	}
	else {
		printf("%s", buf);
		sleep(1);
	}

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	
	exit(0);
}
