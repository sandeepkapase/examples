package main

import "fmt"

type MyStringer interface {
	String() string
}

type Point struct {
	x, y int
}

func (p *Point) String() string {
	return fmt.Sprintf("(%d,%d)", p.x, p.y)
}

func main() {
	var x MyStringer
	fmt.Println(x == nil)           // true because both are nil
	fmt.Println(x == (*Point)(nil)) // false because equal concrete values and different dynamic types

	// above comparison was false because of differnt dynamie type
	// i.e. <nil> and *Point
	fmt.Printf("\n%T", x)
	x = (*Point)(nil)
	fmt.Printf("\n%T", x)
}
