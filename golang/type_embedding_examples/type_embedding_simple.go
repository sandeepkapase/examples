package main

import "fmt"

type Ball struct {
	Radius   int
	Material string
}

type Football struct {
	Ball
}

/* type embedding is used  as in another structure is made memeber of new type with name
Member of embeded type can be accessed directly or with reference to it's structure name
*/
func main() {
	var x Football
	// fb := Football{Ball{Radius: 5, Material: "leather"}}

	x.Radius = 1
	x.Material = "MaterialX"
	fmt.Println(x)

	x.Ball.Radius = 2
	x.Ball.Material = "MaterialY"
	fmt.Println(x)
}
