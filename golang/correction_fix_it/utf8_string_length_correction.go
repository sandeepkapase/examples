package main

import (
	"fmt"
	"unicode/utf8"
)

func main() {
	fmt.Println(len("你好"))
	fmt.Println(utf8.RuneCountInString("你好")) // FIX
	// original output: 6
	// Fixed output: 2
}
