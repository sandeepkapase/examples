package main

import (
	"fmt"
	"reflect"
)

type T struct {
	f1     string "f one"
	f2     string
	f3     string ""
	f4, f5 string `f four and five`
	f6     string `f six`
}

func main() {
	t := reflect.TypeOf(T{})

	f1, _ := t.FieldByName("f1")
	fmt.Println(f1.Tag)

	f2, _ := t.FieldByName("f2")
	fmt.Println(f2.Tag)

	f3, _ := t.FieldByName("f3")
	fmt.Println(f3.Tag)

	f4, _ := t.FieldByName("f4")
	fmt.Println(f4.Tag)

	f5, _ := t.FieldByName("f5")
	fmt.Println(f5.Tag)

	f6, _ := t.FieldByName("f6")
	fmt.Println(f6.Tag)
}
