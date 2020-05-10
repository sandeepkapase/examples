package main

import (
	"fmt"
	"reflect"
)

type S struct {
	a, b, c string
}

func main() {
	x := interface{}(&S{"a", "b", "c"})
	y := interface{}(&S{"a", "b", "c"})

	/* Explainatin: This will print false.
			Interface comparision equals if both interface are nil
			OR Its dynamic type and its value are identical.
			In this case, it's type are identical but values are different.
			Note that here value is not structure value but pointer values.
			Pointer value of x, y are different.

		Correction:
		===========
	1) Change interface value from pointer to actual structure
	    x := interface{}(&S{"a", "b", "c"})
	    y := interface{}(&S{"a", "b", "c"})
	2) Use reflect.DeepEqual for comparision
	*/
	fmt.Println(x == y)                  // false
	fmt.Println(reflect.DeepEqual(x, y)) // true
}
