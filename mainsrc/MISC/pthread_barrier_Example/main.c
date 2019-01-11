#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define THREAD_COUNT 8

pthread_barrier_t mybarrier;

void* threadFn(void *id_ptr) {
  int thread_id = *(int*)id_ptr;
  int wait_sec = 1 + rand() % 5;
  printf("thread %d: Wait for %d seconds.\n", thread_id, wait_sec);
  sleep(wait_sec);
  printf("thread %d: I'm ready...\n", thread_id);

  printf("\nBarrier ret: %d\n", pthread_barrier_wait(&mybarrier));

  printf("thread %d: going!\n", thread_id);
  return NULL;
}


int main() {
  int i;
  pthread_t ids[THREAD_COUNT];
  int short_ids[THREAD_COUNT];

  srand(time(NULL));
  pthread_barrier_init(&mybarrier, NULL, THREAD_COUNT / 2);

  for (i=0; i < THREAD_COUNT; i++) {
    short_ids[i] = i;
    pthread_create(&ids[i], NULL, threadFn, &short_ids[i]);
  }

  printf("main() is ready.\n");

  pthread_barrier_wait(&mybarrier);

  printf("main() is going!\n");

  for (i=0; i < THREAD_COUNT; i++) {
    pthread_join(ids[i], NULL);
  }

  pthread_barrier_destroy(&mybarrier);

  return 0;
}




/* #include<stdio.h> */
/* #include<stdlib.h> */
/* #include<time.h> */
/* #include<unistd.h> */
/* #include<math.h> */
/* #include <pthread.h> */

/* static pthread_barrier_t barrier; */
/* static int numBarriers; */

/* void *threadFunc(void *arg) { */
/*   long threadNum = (long) arg; */
/*   int s; */
/*   printf("Thread num: %ld", threadNum); */
/*   s = pthread_barrier_wait(&barrier); */
/*   printf("Barrier Return: %d", s); */
/*   return 0; */
/* } */


/* int */
/* main(int argc, char *argv[]) */
/* { */
/*   int s, numThreads; */
/*   long threadNum; */
/*   pthread_t *tid; */
  
/*   /\* printf("\nStart main execution %d\n", argc); *\/ */
/*   /\* sleep(1); *\/ */

/*   /\* if (argc != 3) { *\/ */
/*   /\*   printf("\nnum-barriers num-threads\n"); *\/ */
/*   /\*   exit(-1); *\/ */
/*   /\* } *\/ */

/*   /\* numBarriers = atoi(argv[1]); *\/ */
/*   /\* numThreads = atoi(argv[2]); *\/ */

/*   numBarriers = 5; */
/*   numThreads = 10; */

/*   printf("\nnumber of thread : %d", numThreads); */
/*   printf("\nnumber of Barriers :%d" , numBarriers); */
/*   sleep(1); */

/*   /\* Allocate array to hold thread IDs *\/ */

/*   tid = calloc(sizeof(pthread_t), numThreads); */
/*   if (tid == NULL) { */
/*     printf("\ncalloc failure"); */
/*     exit(-1); */
/*   } */

/*   /\* Initialize the barrier. The final argument specifies the */
/*      number of threads that must call pthread_barrier_wait() */
/*      before any thread will unblock from that call. *\/ */

/*   s = pthread_barrier_init(&barrier, NULL, numThreads); */
/*   if (s != 0) { */
/*     printf("\nBarrier init failure"); */
/*     exit(-1); */
/*   } */

/*   /\* Create 'numThreads' threads *\/ */
/*   for (threadNum = 0; threadNum < numThreads; threadNum++) { */
/*     s = pthread_create(&tid[threadNum], NULL, threadFunc, */
/* 		       (void *) threadNum); */
/*     if (s != 0) { */
/*       printf("\nBarrier init failure"); */
/*       exit(-1); */
/*     } */
/*   } */

/*   /\* Each thread prints a start-up message. We briefly delay, */
/*      and then print a newline character so that an empty line */
/*      appears after the start-up messages. *\/ */

/*   usleep(100000); */
/*   printf("\n"); */

/*   /\* Wait for all of the threads to terminate *\/ */

/*   for (threadNum = 0; threadNum < numThreads; threadNum++) { */
/*     s = pthread_join(tid[threadNum], NULL); */
/*     if (s != 0) { */
/*       printf("\nBarrier init failure"); */
/*       exit(-1); */
/*     } */
/*   } */

/*   exit(EXIT_SUCCESS); */
/* } */
