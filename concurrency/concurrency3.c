#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mtx;
pthread_cond_t cond;
int done = 0;

void *handlerA(void *arg) {
  pthread_mutex_lock(&mtx);
  sleep(5);
  done = 1;
  pthread_cond_signal(&cond);

  pthread_mutex_unlock(&mtx);
}

void *handlerB(void *arg) {
  pthread_mutex_lock(&mtx);
  while (done != 1) {
    pthread_cond_wait(&cond, &mtx);
  }
  printf("Done: %d\n", done);
  pthread_mutex_unlock(&mtx);
}

int main() {
  pthread_t thread_id[2];
  int status;
  pthread_mutex_init(&mtx, NULL);
  pthread_cond_init(&cond, NULL);

  pthread_create(&thread_id[0], NULL, handlerA, NULL);
  pthread_create(&thread_id[1], NULL, handlerB, NULL);

  for (int i = 0; i < 2; i++) {
    if (pthread_join(thread_id[i], (void**)&status) != 0) {
      printf("pthread_join()\n");
      return 1;
    }
  }

  pthread_mutex_destroy(&mtx);
  pthread_cond_destroy(&cond);
  return 0;
}