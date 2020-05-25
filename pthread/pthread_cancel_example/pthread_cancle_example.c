/* Simple pthread cancel example*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREAD 4

static void * thread_func(void *ignored_argument) {
  sleep(100000);
  printf("\nShold not be here");
  return NULL;
}

int main(void) {
  pthread_t thr[MAX_THREAD];
  void *res;

  // create threads
  for (int i = 0; i < MAX_THREAD; i++)
    if (pthread_create(&thr[i], NULL, &thread_func, NULL) != 0) {
      printf("\nthread creation failed. Exiting now");
      exit(EXIT_FAILURE);
    }

  sleep(2);

  // cancel threads
  for (int i = 0; i < MAX_THREAD; i++) {
    if (pthread_cancel(thr[i]) != 0) {
      printf("\nThread cancellation failed");
      exit(EXIT_FAILURE);
    }
  }

  // join threads
  for (int i = 0; i < MAX_THREAD; i++) {
    if (pthread_join(thr[i], &res) != 0) {
      printf("\nThread join failed");
      exit(EXIT_FAILURE);
    }
    if (res == PTHREAD_CANCELED)
      printf("\nThread was cancelled");
  }
  return 0;
}
