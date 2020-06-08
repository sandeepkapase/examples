/* Simple pthread conditional variable with pthread_cond_timedwait */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DATA 15
//pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
unsigned int data = 0;

void *thread_func_sender(void *argid) {
  int *id = (int *)argid;
  int waiter = 0;
  while (data == 0) {
    pthread_mutex_lock(&mut);
    while (data == 0) {
      struct timespec max_wait = {0, 0};
      max_wait.tv_sec += 1;
      pthread_cond_timedwait(&cond, &mut, &max_wait);
      printf("\nWait iter:%d", waiter++);
      pthread_mutex_unlock(&mut);
      // DO Something else meanwhile
      sleep(1);
    }
  }
  return NULL;
}

void *thread_func_receiver(void *argid) {
  int *id = (int *)argid;
  sleep(5);
  pthread_mutex_lock(&mut);
  data = 0x1234;
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mut);
  return NULL;
}

int main(void) {
  pthread_t thrSender, thrReceiver;
  int thrName[] = {1, 2, 3, 4};
  
  if (pthread_cond_init(&cond, NULL) != 0) {
    printf("\npthread_cond_init failed");
    exit(EXIT_FAILURE);
  }

  // create threads
  if (pthread_create(&thrSender, NULL, &thread_func_sender, &thrName[0]) != 0) {
    printf("\nthread creation failed. Exiting now");
    exit(EXIT_FAILURE);
  }

  if (pthread_create(&thrReceiver, NULL, &thread_func_receiver, &thrName[1]) != 0) {
    printf("\nthread creation failed. Exiting now");
    exit(EXIT_FAILURE);
  }

  if (pthread_join(thrSender, NULL) != 0) {
    printf("\nThread join failed Sender");
    exit(EXIT_FAILURE);
  }

  if (pthread_join(thrReceiver, NULL) != 0) {
    printf("\nThread join failed Receiver");
    exit(EXIT_FAILURE);
  }
  pthread_cond_destroy(&cond);
  return 0;
}
