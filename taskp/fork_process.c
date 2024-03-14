#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t fork_return;
	int status;

	if ((fork_return = fork()) < 0) {
		perror("fork err");
		exit(1);
	}
	while (1) {
		if (fork_return == 0) {
			printf("child: pid = %d, parent's pid = %d\n", getpid(), getppid());
		} else {
			printf("parent: I have created child with pid = %d\n", fork_return);
		}
		sleep(1000);
	}

	printf("Bye, my pid is %d\n", getpid());
}
