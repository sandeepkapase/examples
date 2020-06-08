/* Simple pthread mutex trylock example */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DATA 100
#define MAX_THREAD 4
pthread_spinlock_t spnlock;
unsigned int data = 0;

static void *thread_func(void *argid) {
  int *id = (int *)argid;
  while (data < MAX_DATA) {
      while(pthread_spin_trylock(&spnlock) != 0) {
      // do something here
      sleep(0);
    }
    printf("\n%d :data %d :id", data++,*id);
    pthread_spin_unlock(&spnlock);
  }
  return NULL;
}

int main(void) {
  pthread_t thr[MAX_THREAD];
  int thrName[MAX_THREAD];

  pthread_spin_init(&spnlock, 0);

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
  pthread_spin_destroy(&spnlock);
  return 0;
}
