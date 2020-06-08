/* Simple Semaphore example */
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DATA 100000
#define MAX_THREADS 8

sem_t sem;
pthread_mutex_t bucket_lock = PTHREAD_MUTEX_INITIALIZER;
int freeIndex[MAX_THREADS]; // free slot index for reader/writer

char process_data[MAX_DATA][10];
int data_index = 0;

void *consumer(void *argid) {
  int *id = (int *)argid;
  int processIndex;
  while (data_index < MAX_DATA) {
    processIndex = -1;
    struct timespec max_wait = {0, 0};
    max_wait.tv_sec += 1;
    while (sem_timedwait(&sem, &max_wait) == -1);

    pthread_mutex_lock(&bucket_lock);
    for (int i = 0; i < MAX_THREADS; i++) {
      if (freeIndex[i] != -1) {
        processIndex = freeIndex[i];
        freeIndex[i] = -1;
      }
    }
    pthread_mutex_unlock(&bucket_lock);

    if (processIndex != -1) {
      printf("\n%s :rdata %d :tid", process_data[processIndex], *id);
    }
  }
  return NULL;
}

void *producer(void *argid) {
  int *id = (int *)argid;
  int writeIndex;
  while (data_index < MAX_DATA) {
    pthread_mutex_lock(&bucket_lock);
    writeIndex = -1;
    for (int i = 0; i < MAX_THREADS; i++) {
      if (freeIndex[i] == -1) {
        freeIndex[i] = data_index++;
        writeIndex = freeIndex[i];
        sem_post(&sem);
        break;
      }
    }
    pthread_mutex_unlock(&bucket_lock);
    if (writeIndex != -1) {
      printf("\n%s :wdata %d :tid", process_data[writeIndex], *id);
    }
    // sleep(0.5);
  }
}

int main(void) {
  pthread_t consumerT[MAX_THREADS], producerT[MAX_THREADS];
  int thrName[MAX_THREADS];
  sem_t *semPtr;

  // init data
  for (int i = 0; i < MAX_THREADS; i++) {
    thrName[i] = i;
    freeIndex[i] = -1;
  }

  // Can also use sem_open instead of sem_init
  /*semPtr = sem_open("testSemaphore", O_CREAT, 0644, 1);
  if (semPtr == SEM_FAILED) {
    printf("\nsemaphore open failed");
    exit(EXIT_FAILURE);
  }
  sem = *semPtr;*/

  if (sem_init(&sem, 0, 0) != 0) {
    printf("\nsemaphore initialization failed");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < MAX_DATA; i++) {
    sprintf(process_data[i], "%d", i);
  }
  // create threads
  for (int i = 0; i < MAX_THREADS; i++) {
    if (pthread_create(&consumerT[i], NULL, &consumer, &thrName[i]) != 0) {
      printf("\nthread creation failed. Exiting now");
      exit(EXIT_FAILURE);
    }
    if (pthread_create(&producerT[i], NULL, &producer, &thrName[i]) != 0) {
      printf("\nthread creation failed. Exiting now");
      exit(EXIT_FAILURE);
    }
  }
  while (data_index < MAX_DATA) {
    sleep(1);
  }

  for (int i = 0; i < MAX_THREADS; i++) {
    // if (pthread_join(consumerT[i], NULL) != 0) {
    if (pthread_cancel(consumerT[i]) != 0) {
      printf("\nThread join/cancel failed consumer");
      //exit(EXIT_FAILURE);
    }
    // if (pthread_join(producerT[i], NULL) != 0) {
    if (pthread_cancel(producerT[i]) != 0) {
      printf("\nThread join/cancel failed producer");
      //exit(EXIT_FAILURE);
    }
  }

  int semVal = -1;
  if (sem_getvalue(&sem, &semVal) != 0) {
    printf("\nSem get val failed.");
    exit(EXIT_FAILURE);
  }
  printf("\nSem val: %d", semVal);
  sem_destroy(&sem);
  return 0;
}
