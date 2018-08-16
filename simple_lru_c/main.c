// test main
// gcc -lpthread -Wall lru.c main.c -o lrutest
// ./lrutest

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/syscall.h>

#include "lru.h"
#include <pthread.h>

#define HEAP_CAPACITY 1000
#define CACHE_SIZE    100
#define MAX_THREADS 10

void * refThread(void *arg) {
    int key,i;
    //pid_t tid = syscall(__NR_gettid);

    cache *c = (cache *)arg;
    srandom((int)time(NULL));
    for (i=0; i<CACHE_SIZE; i++) {
        key = random()%HEAP_CAPACITY;
        refereCache(c, key);
    }
    return NULL;
}

int main(void) {
    int ret,i;
    cache *c = newCache(HEAP_CAPACITY, CACHE_SIZE);
    if (NULL == c)
        return -1;
    pthread_t refThr[MAX_THREADS];

    for (i=0; i<MAX_THREADS; i++) {
        ret = pthread_create(&refThr[i], NULL, refThread, c);
        if (ret != 0) {
            printf("\nThread creation failed\n");
            return -1;
        }
    }
    for (i=0; i<MAX_THREADS; i++)
        pthread_join(refThr[i], NULL);
    return 0;
}
