package main

import (
	"fmt"
)

/* In this example  we have embeded type S1 into S2.
Because of this, methods implemented by S1 are also accessible from S2
instance.
Note that method from embedded method will get called only if the
object that is inherating anther object don't have that method.
i.e. inherating object will override methods from inherited object.
*/

type S1 struct{}

func (s1 S1) f() {
	fmt.Println("S1.f()")
}
func (s1 S1) g() {
	fmt.Println("S1.g()")
}

type S2 struct {
	S1
}

func (s2 S2) f() {
	fmt.Println("S2.f()")
}

func printType(i interface{}) {
	fmt.Printf("%T\n", i)
	if s1, ok := i.(S1); ok {
		s1.f()
		s1.g()
	}
	if s2, ok := i.(S2); ok {
		s2.f()
		s2.g()
	}
}

func main() {
	printType(S1{})
	printType(S2{})
}
