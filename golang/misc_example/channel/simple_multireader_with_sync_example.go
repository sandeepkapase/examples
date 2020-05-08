package main

import "fmt"

import "sync"
import "time"

/* Observations/Notes:
-- In case of number of read, write to channel mismatch then read deadlock occurs
*/

func main() {
	var wg sync.WaitGroup
	quit := make(chan string)
	for _, v := range []int{1, 2, 3, 4, 5} {
		wg.Add(1)
		go testfun(v, quit, &wg)
	}

	for _, v := range []int{1, 2, 3, 4, 5} {
		quit <- fmt.Sprintf("%d", v)
	}

	wg.Wait()
	close(quit)

}

func testfun(id int, quit chan string, wg *sync.WaitGroup) {
	defer wg.Done()
	time.Sleep(2 * time.Second)

	fmt.Println("Started routine:", id)
	msg := <-quit
	switch msg {
	case "quit":
		fmt.Println("Quitting now...")
	default:
		fmt.Println("Channel id:", id, " Message: ", msg)
	}
}
