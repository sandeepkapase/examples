package main

import (
	"fmt"
	"runtime"
	"sync"
)

const N = 26

func main() {
	const GOMAXPROCS = 1
	runtime.GOMAXPROCS(GOMAXPROCS)

	var wg sync.WaitGroup
	wg.Add(2 * N) // wait for 52 goroutines to finish execution
	for i := 0; i < N; i++ {
		go func(i int) {
			defer wg.Done()
			runtime.Gosched()
			fmt.Printf("%c", 'a'+i)
		}(i)
		go func(i int) {
			defer wg.Done()
			fmt.Printf("%c", 'A'+i)
		}(i)
	}
	wg.Wait()
}
