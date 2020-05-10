package main

//import "fmt"

func worker(ch chan struct{}) {
	// Receive a message from the main program.
	println("Worked waiting read")
	<-ch
	println("Worked read done")

	// Send a message to the main program.
	//close(ch)
	ch <- struct{}{}
}

func main() {
	ch := make(chan struct{})
	go worker(ch)

	// Send a message to a worker.
	println("Main writing channle")
	ch <- struct{}{}
	println("Main writing Done")

	// Receive a message from the worker.
	<-ch
	println("Main Done")
}
