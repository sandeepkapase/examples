package main

import "fmt"

type S struct {
	name string
}

/* Explaination:
m["x"] return value and as per go spec left side of assignment must be addressable.
In this case m["x"] return struct value which is not addressable.
So, we modify map so that it holds the pointer value.
Pointer is address, so we can refer struct member with this reference/pointer
*/

func main() {
	//m := map[string]S{"x": S{"one"}}   // PROBLEM
	m := map[string]*S{"x": &S{"one"}} // FIX
	m["x"].name = "two"
	fmt.Println(m["x"].name)
}
