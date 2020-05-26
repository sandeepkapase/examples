#include <pthread.h>
#include <semaphore.h>

typedef struct {
  pthread_mutex_t mutex;
  sem_t readerSignal;
  sem_t writerSignal;
  int active_reader;
  int active_writer;
  int waiting_reader;
  int waiting_writer;
} rwlock;

int rwl_init(rwlock *rwl);
int reader_lock(rwlock *rwl);
int reader_unlock(rwlock *rwl);
int writer_lock(rwlock *rwl);
int writer_unlock(rwlock *rwl);
  
