#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/syscall.h>

#include "lru.h"
#include <pthread.h>

cache * newCache(int heapCapacity, int cacheSize) {
    int i;

    if (heapCapacity < 1 || cacheSize <1) {
        printf("\nHeap/Cache size should be at least 1\n");
        return NULL;
    }

    cache *c = (cache *)malloc(sizeof(cache));

    pthread_mutex_init(&(c->lock), NULL);

    c->cQueue.maxSize = cacheSize;
    c->cQueue.count = 0;
    c->cQueue.front = NULL;
    c->cQueue.rear = NULL;

    c->cHeap.capacity = heapCapacity;
    c->cHeap.arr = malloc(sizeof(c->cHeap.arr)*heapCapacity);
    for (i=0; i < heapCapacity; i++)
        c->cHeap.arr[i] =  NULL;

    return c;
}


static cacheNode *deQueue(cache *c) {
    cacheNode *n = c->cQueue.rear;
    if (n != NULL) {
        c->cHeap.arr[c->cQueue.rear->key] = NULL;
        c->cQueue.rear = c->cQueue.rear->prev;
        if (NULL != c->cQueue.rear)
            c->cQueue.rear->next = NULL;
        else
            c->cQueue.front = NULL;
        c->cQueue.count--;
    }
    return n;
}

static int enQueue(cacheNode *n, cache *c) {
    n->next = c->cQueue.front;
    if (c->cQueue.front != NULL)
        c->cQueue.front->prev = n;
    else
        c->cQueue.rear = n;

    n->prev = NULL;
    c->cQueue.front = n;
    c->cHeap.arr[n->key] = n;
    c->cQueue.count++;
    return 0;
}

static int cacheMiss(cache *c, int key) {
    cacheNode *n;
    if (c->cQueue.count >= c->cQueue.maxSize)
        n = deQueue(c);
    else
        n = (cacheNode *) malloc(sizeof(cacheNode));

    if (NULL == n)
        return -1;

    n->key = key;
    n->data = random(); // backend read/write
    enQueue(n,c);
    return n->data;
}

static int cacheHit(cache *c, int key) {
    cacheNode *n = c->cHeap.arr[key];

    if (n == c->cQueue.front)
        return n->data;

    if (n == c->cQueue.rear) {
        c->cQueue.rear = n->prev;
        c->cQueue.rear->next = NULL;
    } else {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    n->prev = NULL;
    n->next = c->cQueue.front;
    c->cQueue.front->prev = n; // was bug
    c->cQueue.front = n;
    return n->data;
}

static inline int isCacheHit(cache *c, int key) {
    return c->cHeap.arr[key] == NULL ? 0 : 1;
}

/* represent read/write operation.
/ for read  : input = (key)
/ for write : input = (key,data)
/
/ For simplicity we are faking random data,
/ otherwise read/write to/from backend */

int refereCache(cache *c, int key) {
    int ret;

    pthread_mutex_lock(&(c->lock));
    if (key > c->cHeap.capacity) {
        pthread_mutex_unlock(&(c->lock));
        printf("\nKey %d out of heap capacity %d\n", key, c->cHeap.capacity);
        return -1;
    }

    ret = isCacheHit(c,key) ?  cacheHit(c, key) : cacheMiss(c, key);

    pthread_mutex_unlock(&(c->lock));
    return ret;
}
