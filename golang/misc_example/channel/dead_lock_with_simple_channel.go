package main

import (
	"fmt"
)

/* Explaination:
For unbuffered channel, writer is blocked until reader is ready to read value.
So, in below case, "c1 <- 10" blocks execution until someone ready to receive value.
Reader code can not execute because of writer is blocked and hence deadlock.*/

func main() {
	c1 := make(chan int)
	fmt.Println("push c1: ")
	c1 <- 10
	g1 := <-c1
	fmt.Println("get g1: ", g1)
}
