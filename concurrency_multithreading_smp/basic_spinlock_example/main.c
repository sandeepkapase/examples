/* Simple pthread spinlock example */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DATA 100
#define MAX_THREAD 4
pthread_spinlock_t splock;
unsigned int data = 0;

static void *thread_func(void *argid) {
  int *id = (int *)argid;
  while (data < MAX_DATA) {
    pthread_spin_lock(&splock);
    printf("\n%d :data %d :id", data++,*id);
    pthread_spin_unlock(&splock);
  }
  return NULL;
}

int main(void) {
  pthread_t thr[MAX_THREAD];
  int thrName[MAX_THREAD];

  pthread_spin_init(&splock, NULL);

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
  pthread_spin_destroy(&splock);
  return 0;
}
