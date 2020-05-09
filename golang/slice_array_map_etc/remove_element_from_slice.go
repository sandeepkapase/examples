package main

import "fmt"

func main() {
	a := []string{"A", "B", "C", "D", "E"}
	i := 2 // remove "C"
	fmt.Println("Slice:", a)
	fmt.Println("Delete Inded:", i)

	// a[i:] ==> gives pointer on C ==> result { C, D, E}
	// a[i+1:] ==> gives pointer on D ==> result { D, E }
	// In step below will write { D, E } on location { C, D, E} ==> Actual slice value of arr { A, B, D, E, E}
	copy(a[i:], a[i+1:])              // Shift a[i+1:] left one index.
	a[len(a)-1] = ""                  // Erase last element (write zero value).
	a = a[:len(a)-1]                  // Truncate slice.
	fmt.Println("Slice Modified:", a) // [A B D E]
}
