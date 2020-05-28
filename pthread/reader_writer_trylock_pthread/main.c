/* This is vary basic program working with basic reader/writer trylock
   scanario. This need improments/corrections
   CHECK which request processed by which reader writer:
   ./app | grep -E 'RT|WT'| grep -w 1234 ==> request 1234 processed by which
   reader and writer. Compile: gcc -pthread -c reader_writer_lock.c -o
   reader_writer_lock ; gcc -pthread -c main.c -o main ; gcc -pthread
   reader_writer_lock main -o app
*/

#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_SIZE 1000
#define MAX_READER_WRITER 2

int data = 0;

char reader_queue[MAX_SIZE];
pthread_rwlock_t lock = PTHREAD_RWLOCK_INITIALIZER;

void *reader(void *args) {
  static pthread_mutex_t readSync =
      PTHREAD_MUTEX_INITIALIZER; // this may not be requierd if we have
                                 // lockless/atomic read queue
  char *id = (char *)args;
  int i = 0;
  while (1) {
    struct timespec tim1;
    while (pthread_rwlock_tryrdlock(&lock) != 0) {
      // do something here
    }
    pthread_mutex_lock(&readSync); // reader queue synchronization
    if (strlen(reader_queue) != 0) {
      sscanf(reader_queue, "%d", &i);
      printf("\nRT%s:%d", id, i); // reader thread
      bzero(reader_queue, MAX_SIZE);
    }
    pthread_mutex_unlock(&readSync);
    pthread_rwlock_unlock(&lock);
    if (data > MAX_SIZE)
      return NULL; // some condition to quit processing.
  }
}

void *writer(void *args) {
  pthread_mutex_t writeSync =
      PTHREAD_MUTEX_INITIALIZER; // this may not be requierd if we have
                                 // lockless/atomic write queue
  char *id = (char *)args;
  int i = 0;
  while (1) {
    struct timespec tim1;
    tim1.tv_sec = 0;
    while (pthread_rwlock_trywrlock(&lock) != 0) {
      struct timespec tim2;
      tim1.tv_nsec = (rand()%1000)/MAX_READER_WRITER;
      nanosleep(&tim1, &tim2);
    }
    if (strlen(reader_queue) == 0) {
      pthread_mutex_lock(&writeSync); // writer queue synchronization
      i = data++;
      pthread_mutex_unlock(&writeSync); // writer queue synchronization
      printf("\nWT%s:%d.", id, i);      // writer thread
      sprintf(reader_queue, "%d", i++);
    } else {
      sleep(0);
    }
    pthread_rwlock_unlock(&lock);
    if (data > MAX_SIZE)
      return NULL; // some condition to quite processing.
  }
}

int main(void) {
  pthread_t readerT[MAX_READER_WRITER];
  pthread_t writerT[MAX_READER_WRITER];
  char tname[MAX_READER_WRITER][PATH_MAX];
  srand(time(0));

  for (int i = 0; i < MAX_READER_WRITER; i++) {
    sprintf(tname[i], "%d", i);
    pthread_create(&readerT[i], NULL, reader, &tname[i]);
    pthread_create(&writerT[i], NULL, writer, &tname[i]);
  }

  for (int i = 0; i < MAX_READER_WRITER; i++) {
    pthread_join(readerT[i], NULL);
    pthread_join(writerT[i], NULL);
  }
}
