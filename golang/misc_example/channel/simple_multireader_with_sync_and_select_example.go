package main

import "fmt"

import "sync"
import "time"

/* Observations/Notes:
-- Here deadlock may occur, when few goroutine go with default case and by that number of read/write mismatch is there.
-- Possibility of dead lock is more when used unbuffered channnel(blocking channel)
*/

func main() {
	var wg sync.WaitGroup
	quit := make(chan string, 10)
	for _, v := range []int{1, 2, 3, 4, 5} {
		wg.Add(1)
		go testfun(v, quit, &wg)
	}

	for _, v := range []int{1, 2, 3, 4, 5} {
		quit <- fmt.Sprintf("%d", v)
		fmt.Println("Chan Size:", len(quit))
	}

	wg.Wait()
	fmt.Println(len(quit))
	close(quit)

}

func testfun(id int, quit chan string, wg *sync.WaitGroup) {
	time.Sleep(2 * time.Second)
	fmt.Println("Chan Size:", len(quit))
	defer wg.Done()

	select {
	case msg := <-quit:
		fmt.Println("Channel id:", id, " Message: ", msg)
	default:
		fmt.Println("Quitting now...")
	}
}
