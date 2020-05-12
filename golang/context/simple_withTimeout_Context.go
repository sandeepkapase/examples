package main

import (
	"context"
	//	"errors"
	"fmt"
	"time"
)

func main() {
	// we can not take more than two seconds to process request
	ctx, cancel := context.WithTimeout(context.Background(), 2*time.Second)
	//ctx, cancel := context.WithDeadline(parent context.Context, d time.Time)
	defer cancel()

	ch := make(chan string, 1)

	go func() {
		// simulate processing here, processing request
		time.Sleep(2 * time.Second) // making this 3 will result timeout
		// fmt.Println("Now done with result") Note that even after timeout this goroutine will get executed
		ch <- "done"
	}()

	select {
	case msg := <-ch:
		fmt.Println("got result. Return resonse:", msg)
	case <-ctx.Done():
		fmt.Println(ctx.Err())
		fmt.Println("halted operation. Return timeout error")
	}
	time.Sleep(10 * time.Second)
}
