package main

import "fmt"
import "reflect"
import "unsafe"

func main() {
	x := struct{}{}
	fmt.Println("Size of variable:", unsafe.Sizeof(x))
	fmt.Println("Size of variable:", reflect.TypeOf(x).Size())
}
