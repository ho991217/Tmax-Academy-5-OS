#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	pid_t fork_return, d_pid; int exit_status;
	char *const myenv[] = {"sys programming", "is", "fun", (char*)0};

	if ((fork_return = fork()) == -1) {
		perror("fork error");
		exit(-1);
	}
	else if (fork_return == 0) {
		execl("./execl_test2", "./execl_test2", "Hi", "DKU", (char*)0,myenv);
		printf("Child... I'm here\n");
		exit(1);
	}
	else {
		d_pid = wait(&exit_status);
		printf("exit pid = %d with status = %d\n", d_pid, WEXITSTATUS(exit_status));
	}
}
	
