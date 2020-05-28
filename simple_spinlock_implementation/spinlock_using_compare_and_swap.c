/* Simple pthread spinlock implementation example1 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DATA 100000
#define MAX_THREAD 4
pthread_spinlock_t splock;
unsigned int data = 0;

volatile int lock = 0;

int spinlock(volatile int *lock) {
  while (!__sync_bool_compare_and_swap(lock, 0, 1));
  return 0;
}

int spinunlock(volatile int *lock) {
  while (!__sync_bool_compare_and_swap(lock, 1, 0));
  return 0;
}

static void *thread_func(void *argid) {
  int *id = (int *)argid;
  while (data < MAX_DATA) {
    spinlock(&lock);
    printf("\n%d :data %d :id", data++,*id);
    spinunlock(&lock);
  }
  return NULL;
}

int main(void) {
  pthread_t thr[MAX_THREAD];
  int thrName[MAX_THREAD];

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
  return 0;
}
