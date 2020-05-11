package main

type T struct {
	f string "one two three foure"
	// f string `one:"two" three:"foure"` // FIX
}

/* Note that compiler won't throw any error but go vet may report
/* error "not compatible with reflect.StructTag.Get: bad syntax for go*/
/* vet test.go. To fix this issue, one need to provide proper*/
/* key value pair format saperated by space for each key
 */
func main() {}
