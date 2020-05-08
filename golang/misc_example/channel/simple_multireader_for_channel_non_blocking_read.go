package main

import "fmt"

//import "time"

/* Note/Observations:
-- defer and default select may not get chance to execute once program exits
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

	close(quit)

}

func testfun(id int, quit chan string) {
	defer fmt.Println("Exiting routine:", id)

	fmt.Println("Started routine:", id)
	//time.Sleep(10 * time.Second)
	select {
	case msg := <-quit:
		fmt.Println("Channel id:", id, " Message: ", msg)
	default:
		fmt.Println("Quitting now...")
	}
}
