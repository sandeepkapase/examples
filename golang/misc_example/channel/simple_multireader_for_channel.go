package main

import "fmt"

//import "time"

/* Note/Observations:
-- In case of number of write inputs exceed number of read input, deadlock occurs.
-- In case of number of reader (goroutine) exceeds, no side effect. Go routine remain blocked on read and teminate once program exits.
-- defer statement may or may not get executed once program exits
*/
func main() {
	quit := make(chan string)
	for _, v := range []int{1, 2, 3, 4, 5, 6, 7, 9, 10} {
		go testfun(v, quit)
	}

	for _, v := range []int{1, 2, 3, 4, 5} {
		quit <- fmt.Sprintf("%d", v)
	}

	fmt.Println("Done message passing")
	//time.Sleep(20 * time.Second)

	//close(quit)

}

func testfun(id int, quit chan string) {
	defer fmt.Println("Exiting routine:", id)

	fmt.Println("Started routine:", id)
	//time.Sleep(10 * time.Second)
	msg := <-quit
	switch msg {
	case "quit":
		fmt.Println("Quitting now...")
	default:
		fmt.Println("Channel id:", id, " Message: ", msg)
	}
}
