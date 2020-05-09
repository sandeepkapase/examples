package main

import "fmt"

/*
array have two properties:
length = len(arr) ==> how many elementes are there in array
capacity = len(arr) ==> capacity of array
eg.
 arr := []int{2, 3, 5, 7, 11, 13}

slicing required two input 'x' and 'y' numbers
Eg. arr[x:y]
    Resultant capacity = existing capacity - x
    Resultant length   = y - x
    Conditions ==> y > x always, y should be greated current capacity of arr
    resultant array will start point to 'current pointer' + x

   arr[0:4] ==> {2, 3, 5, 7}
   arr[2:4] ==> {5, 7}
*/

func main() {
	s := []int{2, 3, 5, 7, 11, 13}
	printSlice(s)

	// Slice the slice to give it zero length.
	s = s[:0]
	printSlice(s)

	// Extend its length.
	s = s[:4]
	printSlice(s)

	// Drop its first two values.
	s = s[2:4] // not that this will reset pointer of s to third element of s
	printSlice(s)

	// Drop its first two values.
	s = s[:4]
	printSlice(s)

}

func printSlice(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}
