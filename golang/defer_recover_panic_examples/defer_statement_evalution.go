package main

import "fmt"

func a() {
	i := 0
	defer fmt.Println(i)
	i = 20
	defer fmt.Println(i)
	i = 200
	return
}

func main() {
	a()
}
