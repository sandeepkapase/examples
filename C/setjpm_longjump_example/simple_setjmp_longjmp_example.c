#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

/* In example below, during nested call execution
we will directly jump to setjmp entrypoint from function five.
i.e. after longjump in "five" we will not go back to previous
call stack execution and directly start execution marked at 
setjmp location.
If we comment longjmp, we can see call stack is executed as usually
Note:
* After longjmp execution will resume at a point where are called
setjmp and return value will be value returned from longjmp.
We can return different value at different point and handle return
value after jump back to setjmp location.
* if we don't handle return value then there will be infinite loop.
  Try putting setjmp outside if conditions. Only initial return will
  be zero and subsequent will be set at longjmp.
*/
jmp_buf resume_buf;

void five(void) {
  printf("\nEntry five.");
  // some processing here
  // Error occured here
  // instead of returning to caller, long jump to main.
  // if (error)
  longjmp(resume_buf,1);
  printf("\nReturn five.");
}

void four(void) {
  printf("\nEntry four.");
  five();
  // some processing here
  printf("\nReturn four.");
}

void three(void) {
  printf("\nEntry three.");
  four();
  // some processing here
  printf("\nReturn three.");
}

void two(void) {
  printf("\nEntry two.");
  three();
  // some processing here
  printf("\nReturn two.");
}

void one(void) {
  printf("\nEntry one.");
  two();
  // some processing here
  printf("\nReturn one.");
}

void mainoperation(void) {
  printf("\nEntry mainoperation.");
  one();
  printf("\nReturn mainoperation.");
}

int main(void) {
  int ret;
  ret = setjmp(resume_buf);
  printf("\nReturn value:%d", ret); // print two times. one from
                                    // setjmp and other after longjmp.
  //mainoperation(); // infinit loop uncommented
  if (ret == 0) {
    printf("\nStarting operation");
    mainoperation();
    printf("\nCompleted operation");
  } else {
    printf("\nmainoperation reported error");
  }
}

