#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *handler(void *arg) {
  int a = *((int *)arg);
  printf("Thread %d\n", a);
  return NULL;
}

int main(void) {
  pthread_t thread_id;
  int a = 3;
  if(pthread_create(&thread_id, NULL, handler, (void*)&a) != 0) {
    printf("Failed to create thread\n");
    return 1;
  }

  sleep(2);
  return 0;
}