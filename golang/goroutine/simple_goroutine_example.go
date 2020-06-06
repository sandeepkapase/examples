package main

import "fmt"

const MAX_THREAD = 10

func worker(done chan bool) {
	fmt.Println("started worker")
	for i := 0; i < 1000000000; i++ {
	}
	fmt.Println("finishing worker")
	done <- true
}

func main() {
	done := make(chan bool)
	fmt.Println("Started main")
	for i := 0; i < MAX_THREAD; i++ {
		go worker(done)
	}
	for i := 0; i < MAX_THREAD; i++ {
		<-done
	}
}
