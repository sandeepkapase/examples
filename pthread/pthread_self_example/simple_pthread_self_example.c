/* Simple pthread self example */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREAD 4

static void * thread_func(void *ignored_argument) {
  sleep(5);
  if (pthread_cancel(pthread_self())!= 0)
    printf("\nFailed to cancel self");
  sleep(5);
  printf("\nShould not be here");
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

  // join threads
  for (int i = 0; i < MAX_THREAD; i++) {
    if (pthread_join(thr[i], &res) != 0) {
      printf("\nThread join failed");
      exit(EXIT_FAILURE);
    }
    if (res == PTHREAD_CANCELED)
      printf("\nThread was cancelled");
    else
      printf("\nReturn status should have been PTHREAD_CANCELED");
  }
  return 0;
}
