#include "reader_writer_lock.h"
#include <pthread.h>

int rwl_init(rwlock *rwl) {
  rwl->active_reader = rwl->active_writer = 0;
  rwl->waiting_reader = rwl->waiting_writer = 0;
  pthread_mutex_init(&rwl->mutex, NULL);
  pthread_cond_init(&rwl->readerSignal, NULL);
  pthread_cond_init(&rwl->writerSignal, NULL);
  return 0;
}

int reader_lock(rwlock *rwl) {
  // get mutex lock
  pthread_mutex_lock(&rwl->mutex);
  // reader lock only blocker by writer block
  // if there are active writer then increment waiting_reader count for self.
  if (rwl->active_writer) {
    rwl->waiting_reader++;

    // wait till there are no active writer
    // writer_unlock will send signal
    while (rwl->active_writer)
      pthread_cond_wait(&rwl->readerSignal, &rwl->mutex);

    // Now reduce wait counter for self
    rwl->waiting_reader--;
  }
  // Increment activer reader count for self
  rwl->active_reader++;
  return pthread_mutex_unlock(&rwl->mutex);
}

int writer_lock(rwlock *rwl) {
  // get mutex lock
  pthread_mutex_lock(&rwl->mutex);
  // writer lock gets blocked by other reader and writer block
  // if there are active reader, writer then increment waiting_writer count for

  // wait till there are no active writer
  // writer_unlock will send signal
  if (rwl->active_writer || rwl->active_reader) {
    rwl->waiting_writer++;

    // wait till there are no active reader, writer
    // writer_unlock, read_unlock will send signal
    while (rwl->active_writer || rwl->active_reader)
      pthread_cond_wait(&rwl->writerSignal, &rwl->mutex);

    // Now reduce wait counter for self
    rwl->waiting_writer--;
  }
  // Increment activer reader count for self
  rwl->active_writer=1;
  return pthread_mutex_unlock(&rwl->mutex);
}

int reader_unlock(rwlock *rwl) {
  pthread_mutex_lock(&rwl->mutex);
  rwl->active_reader--;

  if (rwl->active_reader == 0 && rwl->waiting_writer > 0)
    pthread_cond_broadcast(&rwl->writerSignal);
  return pthread_mutex_unlock(&rwl->mutex);
}

int writer_unlock(rwlock *rwl) {
  pthread_mutex_lock(&rwl->mutex);
  rwl->active_writer=0;

  if (rwl->waiting_reader)
    pthread_cond_broadcast(&rwl->readerSignal);
  if (rwl->waiting_writer)
    pthread_cond_broadcast(&rwl->writerSignal);

  return pthread_mutex_unlock(&rwl->mutex);
}
