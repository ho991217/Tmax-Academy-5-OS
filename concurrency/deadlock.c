#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int global = 0;
pthread_mutex_t mtx;

void *handler(void *arg) {
  pthread_mutex_lock(&mtx);
  global++;
  if(global == 1) {
    return NULL;
  }

  pthread_mutex_unlock(&mtx);
}

int main() {
  pthread_t thread_id[2];
  int status;
  pthread_mutex_init(&mtx, NULL);
  for (int i = 0; i < 2;i++) {
    if (pthread_create(&thread_id[i], NULL, handler, NULL) != 0) {
      printf("Failed to create thread\n");
      return 1;
    }
  }

  for (int i = 0; i < 2; i++) {
    if (pthread_join(thread_id[i], (void**)&status) != 0) {
      printf("Failed to join thread\n");
      return 1;
    }
  }

  printf("Global: %d\n", global);
  pthread_mutex_destroy(&mtx);
  return 0;
}