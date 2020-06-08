#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define MSG_LEN 50
int main() {
  int p1_io[2];
  char str_msg[MSG_LEN];

  pipe(p1_io);

  if (fork() == 0) { // child
    dup2(p1_io[0], 0); // 0 descriptor represent to reading end of pipe.
    read(0, str_msg, MSG_LEN);
    printf("\nMessage from parent: %s\n", str_msg);
    sleep(5);
  } else { //parent
    dup2(p1_io[1], 1); // 1 descriptor represent to writing end of pipe.
    char *data = "\nPlease listen to me carefully\n";
    write(1, data, MSG_LEN);
    sleep(5);
  }
  return 0;
}

