/* Simple pthread mutex example */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
#define MAX_DATA 100
#define MAX_THREAD 4
pthread_mutex_t mut;
unsigned int data = 0;

static void *thread_func(void *argid) {
  int *id = (int *)argid;
  while (data < MAX_DATA) {
    pthread_mutex_lock(&mut);
    printf("\n%d :data %d :id", data++,*id);
    pthread_mutex_unlock(&mut);
  }
  return NULL;
}

int main(void) {
  pthread_t thr[MAX_THREAD];
  int thrName[MAX_THREAD];

  pthread_mutex_init(&mut, NULL);

  // create threads
  for (int i = 0; i < MAX_THREAD; i++) {
    thrName[i] = i + 1;
    if (pthread_create(&thr[i], NULL, &thread_func, &thrName[i]) != 0) {
      printf("\nthread creation failed. Exiting now");
      exit(EXIT_FAILURE);
    }
  }

  // join threads
  for (int i = 0; i < MAX_THREAD; i++) {
    if (pthread_join(thr[i], NULL) != 0) {
      printf("\nThread join failed");
      exit(EXIT_FAILURE);
    }
  }
  pthread_mutex_destroy(&mut);
  return 0;
}
