#include "reader_writer_lock.h"
#include <pthread.h>
#include <semaphore.h>

int rwl_init(rwlock *rwl) {
  rwl->active_reader = rwl->active_writer = 0;
  rwl->waiting_reader = rwl->waiting_writer = 0;
  pthread_mutex_init(&rwl->mutex, NULL);
  sem_init(&rwl->readerSignal, 0, 1);
  sem_init(&rwl->writerSignal, 0, 1);
  return 0;
}

int reader_lock(rwlock *rwl) {
  // get mutex lock
  pthread_mutex_lock(&rwl->mutex);
  rwl->waiting_reader++;
  while (1){
    pthread_mutex_unlock(&rwl->mutex);
    // reader gets block only by writer
    sem_wait(&rwl->writerSignal); // wait for signal
    pthread_mutex_lock(&rwl->mutex);
    sem_post(&rwl->writerSignal); // wait for signal
    if (rwl->active_writer == 0) {
      rwl->waiting_reader--;
      rwl->active_reader++;
      //sem_post(&rwl->writerSignal); // unblock next
      return pthread_mutex_unlock(&rwl->mutex);
    }
  }
}

int writer_lock(rwlock *rwl) {
  // get mutex lock
  pthread_mutex_lock(&rwl->mutex);
  rwl->waiting_writer++;
  while (1){
    pthread_mutex_unlock(&rwl->mutex);
    // writer gets blocked by reader and writer
    sem_wait(&rwl->writerSignal); // wait for signal
    sem_wait(&rwl->readerSignal); // wait for signal
    pthread_mutex_lock(&rwl->mutex);
    sem_post(&rwl->writerSignal);
    sem_post(&rwl->readerSignal);
    if (rwl->active_writer == 0 && rwl->active_reader == 0) {
      rwl->waiting_writer--;
      rwl->active_writer=1; // at most there can be only one writer at a time.
      return pthread_mutex_unlock(&rwl->mutex);
    }
  }
}

int writer_unlock(rwlock *rwl) {
  pthread_mutex_lock(&rwl->mutex);
  rwl->active_writer=0;

  for (int i=0; i<rwl->active_writer+1; i++) {
    sem_post(&rwl->writerSignal);
    sem_post(&rwl->readerSignal);
  }

  for (int i=0; i<rwl->active_reader+1; i++) {
    sem_post(&rwl->writerSignal);
  }

  return pthread_mutex_unlock(&rwl->mutex);
}

int reader_unlock(rwlock *rwl) {
  pthread_mutex_lock(&rwl->mutex);
  //if (rwl->active_reader-1 >= 0)
    rwl->active_reader--;

  for (int i=0; i<rwl->active_writer; i++) {
    sem_post(&rwl->writerSignal);
    sem_post(&rwl->readerSignal);
  }

  return pthread_mutex_unlock(&rwl->mutex);
}
