package main

import "fmt"

type Bouncer interface {
	Bounce()
}

type Ball struct {
	Radius   int
	Material string
}

func (b Ball) Bounce() {
	fmt.Println("Bouncing ball. Radius:", b.Radius, "Material:", b.Material)
}

type Football struct {
	Ball
}

/* type embedding is used  as in another structure is made memeber of new type with name
Member of embeded type can be accessed directly or with reference to it's structure name
Interface implemented by original type will also be available on new type
*/
func main() {
	var x Football

	x.Radius = 1
	x.Material = "MaterialX"
	x.Bounce()

}
