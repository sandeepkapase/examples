package main

import "fmt"

var c = make(chan struct{})

func main() {
	for i := 1; i < 10000001; i++ {
		go func(x int) {
			if x == 10000000 {
				fmt.Println("hi number {} !", x)
				c <- struct{}{}
			}
		}(i)
	}
	<-c
}
