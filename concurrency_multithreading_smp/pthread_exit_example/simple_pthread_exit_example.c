/* Simple pthread_exit example */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREAD 4

static void *thread_func(void *ignored_argument) {
  sleep(5);
  int *ptr = malloc(sizeof(int));
  *ptr = 123;
  pthread_exit(ptr);
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

  // join threads
  for (int i = 0; i < MAX_THREAD; i++) {
    if (pthread_join(thr[i], &res) != 0) {
      printf("\nThread join failed");
      exit(EXIT_FAILURE);
    }
    printf("\nThread was cancelled:%d", *(int *)res);
  }
  return 0;
}
