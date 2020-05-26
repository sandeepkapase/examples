/* This is vary basic program working with basic reader, writer lock
   using semaphore. This need improments/corrections
   CHECK which request processed by which reader writer:
   ./app | grep -E 'RT|WT'| grep -w 1234 ==> request 1234 processed by which reader and writer.
   Compile: gcc -pthread -c reader_writer_lock.c -o reader_writer_lock ; gcc -pthread -c main.c -o main ; gcc -pthread reader_writer_lock main -o app 
*/

//#include "reader_writer_lock.h"
#include "reader_writer_lock.c"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#define MAX_SIZE 10000
#define MAX_READER_WRITER 4

int data=0;

rwlock lock; // this is implemented rwlock structure
char reader_queue[MAX_SIZE];

void printlock(void) {
  printf("\nActive reader:%d", lock.active_reader);
  printf("\nActive writer:%d", lock.active_writer);
  printf("\nWaiting reader:%d", lock.waiting_reader);
  printf("\nWaiting reader:%d", lock.waiting_writer);
}


void * reader(void *args) {
  static pthread_mutex_t readSync = PTHREAD_MUTEX_INITIALIZER; // this may not be requierd if we have lockless/atomic read queue
  char *id = (char*) args;
  int i=0;
  while (1) {
    reader_lock(&lock);
    pthread_mutex_lock(&readSync); // reader queue synchronization
    if (strlen(reader_queue) != 0) {
      sscanf(reader_queue, "%d", &i);
      printf("\nRT%s:%d", id, i); // reader thread
      bzero(reader_queue, MAX_SIZE);
    }
    pthread_mutex_unlock(&readSync);
    reader_unlock(&lock);
    if (data > MAX_SIZE ) return NULL; // some condition to quit processing.
  }
}

void * writer(void *args) {
  pthread_mutex_t writeSync = PTHREAD_MUTEX_INITIALIZER; // this may not be requierd if we have lockless/atomic write queue
  char *id = (char *)args;
  int i=0;
  while(1) {
    writer_lock(&lock);
    if (strlen(reader_queue) == 0) {
      pthread_mutex_lock(&writeSync); // writer queue synchronization
      i = data++;
      pthread_mutex_unlock(&writeSync); // writer queue synchronization
      printf("\nWT%s:%d.", id, i); // writer thread
      sprintf(reader_queue, "%d", i++);
    } else {
      sleep(0);
    }
    writer_unlock(&lock);
    if (data > MAX_SIZE ) return NULL; // some condition to quite processing.
    }
}

int main(void) {
  pthread_t readerT[MAX_READER_WRITER];
  pthread_t writerT[MAX_READER_WRITER];
  char tname[MAX_READER_WRITER][PATH_MAX];

  rwl_init(&lock);
  for (int i = 0; i < MAX_READER_WRITER; i++) {
    sprintf(tname[i], "%d", i);
    pthread_create(&readerT[i], NULL, reader, &tname[i]);
    pthread_create(&writerT[i], NULL, writer, &tname[i]);
  }

  for (int i = 0; i < MAX_READER_WRITER; i++) {
    pthread_join(readerT[i], NULL);
    pthread_join(writerT[i], NULL);
  }
  printlock();
}
