#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t fork_return, d_pid; int exit_status = -1;
	
	if ((fork_return = fork()) == -1) {
		perror("fork error");
		exit(1);
	}
	else if (fork_return == 0) {
		execl("./hello", "./hello", (char *)0);
		printf("Child... I'm here\n");
		exit(1);
	}
	else {
		d_pid = wait(&exit_status);
		printf("Parent... I'm here\n");
		printf("exit status of task %d is %d\n", d_pid, exit_status);
	}
}
