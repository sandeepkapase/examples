#include <pthread.h>

typedef struct {
  pthread_mutex_t mutex;
  pthread_cond_t readerSignal;
  pthread_cond_t writerSignal;
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
  
