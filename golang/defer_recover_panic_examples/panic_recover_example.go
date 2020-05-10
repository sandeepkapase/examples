package main

import "fmt"

func main() {
	f()
	fmt.Println("Returned normally from f.")
}

func f() {
	defer fmt.Println("Back to ffffffffffffff......")
	defer func() {
		if r := recover(); r != nil {
			fmt.Println("Recovered in f", r)
		}
		//fmt.Println("removed recover")
	}()
	fmt.Println("Calling g.")
	g(0)
	fmt.Println("Returned normally from g.")
}

func g(i int) {
	if i > 3 {
		fmt.Println("Panicking!")
		panic(fmt.Sprintf("Reported panic with value %v", i))
	}
	defer fmt.Println("Defer in g", i)
	fmt.Println("Printing in g", i)
	g(i + 1)
}
