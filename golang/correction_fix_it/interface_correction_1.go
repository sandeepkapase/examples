package main

import "fmt"

type Orange struct {
	Quantity int
}

func (o *Orange) Increase(n int) {
	o.Quantity += n
}

func (o *Orange) Decrease(n int) {
	o.Quantity -= n
}

//func (o Orange) String() string { // This is correction
func (o *Orange) String() string {
	return fmt.Sprintf("--> %v", o.Quantity)
}

// In program above method "String" will not get execute because it is
// implemented for pointer value
// So, chaging that to actual object value will implement that method
// for that object as well as it's pointer
func main() {
	var orange Orange
	orange.Increase(10)
	orange.Decrease(5)
	// This won't invoke "String"  as "String" is implemented for pointer
	// To fix this we need to implement "String" for object which will include object and it's pointer as well
	fmt.Println("Val with obj:", orange)

	orangePtr := &orange
	fmt.Println("Val with ptr:", orangePtr)
}
