/* Simple pthread conditional variable with pthread_cond_broadcast */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DATA 15
#define MAX_THREAD 9
//pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
unsigned int data = 0;

static void *thread_func(void *argid) {
  int *id = (int *)argid;
  while (data < MAX_DATA) {
    pthread_mutex_lock(&mut);
    while (data % *id != (*id) - 1 && data < MAX_DATA)
      pthread_cond_wait(&cond, &mut);
    if (data < MAX_DATA) {
      printf("\nIncrementing data in thread:%d data:%d", *id, data++);
    }
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mut);
    sleep(1);
  }
  return NULL;
}

int main(void) {
  pthread_t thr[MAX_THREAD];
  int thrName[MAX_THREAD];

  if (pthread_cond_init(&cond, NULL) != 0) {
    printf("\npthread_cond_init failed");
    exit(EXIT_FAILURE);
  }

  // create threads
  for (int i = 0; i < MAX_THREAD; i++) {
    thrName[i] = i + 1;
    if (pthread_create(&thr[i], NULL, &thread_func, &thrName[i]) != 0) {
      printf("\nthread creation failed. Exiting now");
      exit(EXIT_FAILURE);
    }
  }

  sleep(2);

  // join threads
  for (int i = 0; i < MAX_THREAD; i++) {
    if (pthread_join(thr[i], NULL) != 0) {
      printf("\nThread join failed");
      exit(EXIT_FAILURE);
    }
  }
  pthread_cond_destroy(&cond);
  return 0;
}
