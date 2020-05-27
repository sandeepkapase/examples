/* Simple pthread conditional variable with pthread_cond_signal */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DATA 15
//pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
unsigned int data = 0;

void *thread_func_even(void *argid) {
  int *id = (int *)argid;
  while (data < MAX_DATA) {
    pthread_mutex_lock(&mut);
    while (data % 2 != 0 && data < MAX_DATA)
      pthread_cond_wait(&cond, &mut);

    printf("\nEven thread:%d data:%d", *id, data++);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mut);
    sleep(1);
  }
  return NULL;
}

void *thread_func_odd(void *argid) {
  int *id = (int *)argid;
  while (data < MAX_DATA) {
    pthread_mutex_lock(&mut);
    while (data % 2 != 1 && data < MAX_DATA)
      pthread_cond_wait(&cond, &mut);

    printf("\nOdd thread:%d data:%d", *id, data++);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mut);
    sleep(1);
  }
  return NULL;
}

int main(void) {
  pthread_t thrEven, thrOdd;
  int thrName[] = {1, 2, 3, 4};
  if (pthread_cond_init(&cond, NULL) != 0) {
    printf("\npthread_cond_init failed");
    exit(EXIT_FAILURE);
  }

  // create threads
  if (pthread_create(&thrEven, NULL, &thread_func_even, &thrName[0]) != 0) {
    printf("\nthread creation failed. Exiting now");
    exit(EXIT_FAILURE);
  }

  if (pthread_create(&thrOdd, NULL, &thread_func_odd, &thrName[1]) != 0) {
    printf("\nthread creation failed. Exiting now");
    exit(EXIT_FAILURE);
  }

  if (pthread_join(thrEven, NULL) != 0) {
    printf("\nThread join failed Even");
    exit(EXIT_FAILURE);
  }

  if (pthread_join(thrOdd, NULL) != 0) {
    printf("\nThread join failed Odd");
    exit(EXIT_FAILURE);
  }
  pthread_cond_destroy(&cond);
  return 0;
}
