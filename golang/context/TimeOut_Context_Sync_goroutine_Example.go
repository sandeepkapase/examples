package main

import (
	"context"
	"fmt"
	"sync"
	"time"
)

func main() {
	timeOutContext, _ := context.WithTimeout(context.Background(), 5*time.Second)
	wg := sync.WaitGroup{}
	wg.Add(3)

	contextDemo := func(name string, ctx context.Context) {
		defer wg.Done()
		for {
			select {
			case <-timeOutContext.Done():
				fmt.Println("Quitting .... Timeout Done for ", name)
				return
			default:
				fmt.Println("Running:", name)
			}
			time.Sleep(1 * time.Second)
		}
	}

	go contextDemo("[timeoutContextX]", timeOutContext)
	go contextDemo("[timeoutContextY]", timeOutContext)
	go contextDemo("[timeoutContextZ]", timeOutContext)

	fmt.Println("Waiting now")
	wg.Wait()
	fmt.Println("Exiting now")
}
