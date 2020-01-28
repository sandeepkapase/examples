package main

import (
	"fmt"
	"reflect"
	"runtime"
)

func main() {
	anonymousFunction1, anonymousFunction2 := getAnonymousFunction()
	method := (*A).Method
	fmt.Println("Named function:     ", nameOf(namedFunction))
	fmt.Println("Anonymous functions:", nameOf(anonymousFunction1), ",", nameOf(anonymousFunction2))
	fmt.Println("Method:             ", nameOf(method))
}

func nameOf(f interface{}) string {
	v := reflect.ValueOf(f)
	if v.Kind() == reflect.Func {
		if rf := runtime.FuncForPC(v.Pointer()); rf != nil {
			return rf.Name()
		}
	}
	return v.String()
}

func namedFunction() {
}

func getAnonymousFunction() (func(), func()) {
	anonymous1 := func() {}
	anonymous2 := func() {}
	return anonymous1, anonymous2
}

type A struct{ x, y int }

func (*A) Method() {}
