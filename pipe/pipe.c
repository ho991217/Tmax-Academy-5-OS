#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void parent_process(int *counter, int rfd);
void child_process(int rfd);

int main() {
  pid_t pid;
  int counter = 3;
  int pipefd[2];

  if (pipe(pipefd) == -1) {
    perror("pipe");
    return 1;
  }
  pid = fork();

  if (pid < 0) {
    perror("fork()");
    return 1;
  } else if (pid == 0) {
    close(pipefd[1]);
    child_process(pipefd[0]);
  } else {
    close(pipefd[0]);
    parent_process(&counter, pipefd[1]);
  }

  int status;
  wait(&status);
  return 0;
}

void parent_process(int *counter, int rfd) {
  *counter += 1;
  printf("Parent: %d\n", *counter);
  write(rfd, counter, sizeof(*counter));
}

void child_process(int rfd) {
  int counter;
  read(rfd, &counter, sizeof(counter));
  printf("Child: %d\n", counter);
}