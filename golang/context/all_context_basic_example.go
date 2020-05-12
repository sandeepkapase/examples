package main

import "context"
import "time"
import "fmt"

func main() {

	deadlineContext, _ := context.WithDeadline(context.Background(), time.Now().Add(3*time.Second))
	timeOutContext, _ := context.WithTimeout(context.Background(), 4*time.Second)
	cancelContext, cancelFunc := context.WithCancel(context.Background())

	worker := func(name string, ctx context.Context) {
		time.Sleep(5 * time.Second)
		cancelFunc()
		fmt.Println("ContextType:", name)
	}

	go worker("[deadlineContext]", deadlineContext)
	go worker("[timeoutContext]", timeOutContext)
	go worker("[cancelContext]", cancelContext)

	<-timeOutContext.Done()
	fmt.Println("Returned timeout Context")

	<-deadlineContext.Done()
	fmt.Println("Deadline Context")

	<-cancelContext.Done()
	fmt.Println("Cancel Cancel Context")
}
