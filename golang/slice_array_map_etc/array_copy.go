package main

import "fmt"

/*
array have two properties:
length = len(arr) ==> how many elementes are there in array
capacity = len(arr) ==> capacity of array
eg.
 arr := []int{2, 3, 5, 7, 11, 13}

copy function can be used to copy slice from on to another
Eg. copy(destination, src)
    if src is not empty then src will overwrite to destination changing its capacity and len
*/

func main() {
	s2 := []int{4, 5, 6}
	s3 := []int{7, 8, 9, 10, 11, 13}
	s4 := []int{14, 15}
	s5 := []int{} // for this case destination properties cap, len will not be changed

	s1 := []int{1, 2, 3}
	copy(s1, s2)
	printSlice(s1, s2)

	s1 = []int{1, 2, 3}
	copy(s1, s3)
	printSlice(s1, s3)

	s1 = []int{1, 2, 3}
	copy(s1, s4)
	printSlice(s1, s4)

	s1 = []int{1, 2, 3}
	copy(s1, s5)
	printSlice(s1, s5)
}

func printSlice(src []int, dst []int) {
	fmt.Printf("SRC len=%d cap=%d %v\n", len(src), cap(src), src)
	fmt.Printf("DST len=%d cap=%d %v\n", len(dst), cap(dst), dst)
	fmt.Println("\n")
}
