/* Simple pthread example */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define MAX_SENDER_THREAD 50
#define MSG_SIZE 10

void * email_sender(void *arg) {
  printf("\nSending email:%s", (char *)arg);
  // send email here
  sleep(1);
}

int main(void) {
  pthread_t sender_thread[MAX_SENDER_THREAD];
  char sender_msg[MAX_SENDER_THREAD][MSG_SIZE];

  for (int i=0; i<MAX_SENDER_THREAD; i++) {
    sprintf(sender_msg[i], "Message:%d", i);
    pthread_create(&sender_thread[i], NULL, email_sender, &sender_msg[i]);
  }

  for (int i=0; i<MAX_SENDER_THREAD; i++)
    pthread_join(sender_thread[i], NULL);

  return 0;
}
