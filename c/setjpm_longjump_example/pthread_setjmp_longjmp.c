#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <pthread.h>
#include <unistd.h>

jmp_buf resume_buf;

void somefunction() {
    printf("\nStarted somefunctoin");
    //sleep(1);
    printf("\nDoing longjmp");
    longjmp(resume_buf, 1);
    printf("\nReturning from somefunctoin");
}

void *setJmpThread(void *vargp) 
{ 
    printf("\nSetjmp thread started");
    int ret = setjmp(resume_buf);
    if (ret == 0 ) {
        printf("\nSetjmp done, sleeping now");
        somefunction();
        printf("\nsomefunction returned without jump");
    } else {
        printf("\nLong jmp from Happened. Sleeping now");
    }
        printf("\nReturning from thread");
} 


int main(void) {
    pthread_t thread_id_setJmp; 

    pthread_create(&thread_id_setJmp, NULL, setJmpThread, NULL); 

    //sleep(600);
    pthread_join(thread_id_setJmp, NULL); 

    printf("After Thread\n"); 
    exit(0);  
}


