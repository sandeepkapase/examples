#include <pthread.h>


// lru.c
struct cacheNode;
typedef struct cacheNode cacheNode;
struct cacheNode {
    cacheNode *next, *prev;
    int key;                 // block/page no.
    int data;                // block/page data.
};


struct cacheQueue;
typedef struct cacheQueue cacheQueue;
struct cacheQueue {
    int maxSize;            // ssd bloks/ram frames
    int count;              // used
    cacheNode *front, *rear;
};


struct cacheHeap;
typedef struct cacheHeap cacheHeap;
struct cacheHeap {
    int capacity;           // disk bloks/page no.
    cacheNode **arr;        // pointer array (index based on key/block
};

struct cache;
typedef struct cache cache;
struct cache {
    pthread_mutex_t lock;   // concurrent access/multithreading
    cacheQueue cQueue;      // FIFO
    cacheHeap cHeap;        // O(1) search
};

int refereCache(cache *csh, int key);
cache * newCache(int heapCapacity, int cacheSize);
void destroyCache(cache *);
