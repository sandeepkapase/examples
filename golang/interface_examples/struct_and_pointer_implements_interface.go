package main

import "fmt"

type miscInterface interface {
	square() int
}

type miscStruct struct {
	data int
}

//func (t *miscStruct) add() int { // Both implementation on type or on poninter of that type has same effect
func (t miscStruct) add() int {
	return t.data * t.data
}

// note that if we uncomment below function
// we will get error "method redeclared: miscStruct.add "
// i.e. by compiler both are treated as same
/*func (t *miscStruct) add() int {
	return t.data * t.data
}*/

/* Here not that while structure "miscStruct" implement interface
miscInterface, interface is also implement for its pointer as well */

func main() {
	mvar := miscStruct{data: 8}
	var mvarPtr *miscStruct = &mvar
	fmt.Println(mvar.add())
	fmt.Println(mvarPtr.add())
}
