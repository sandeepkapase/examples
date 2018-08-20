#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/syscall.h>

#include "lru.h"
#include <pthread.h>

void printFromRear(cache *c) {
    cacheNode *n = c->cQueue.rear;
    while (n != c->cQueue.front && n != NULL) {
        printf("%d ", n->key);
        n = n->prev;
    }

    if (n!= NULL)
        printf("%d", n->key);
    printf("\n");
}

void printFromFront(cache *c) {
    cacheNode *n = c->cQueue.front;
    while (n != c->cQueue.rear && n != NULL) {
        printf("%d ", n->key);
        n = n->next;
    }

    if (n!= NULL)
        printf("%d", n->key);
    printf("\n");
}
