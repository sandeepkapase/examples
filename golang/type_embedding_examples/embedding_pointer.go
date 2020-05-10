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
	*Ball // note embedding pointer here
}

/* type embedding is used  as in another structure is made memeber of new type with name
Member of embeded type can be accessed directly or with reference to it's structure name
Interface implemented by original type will also be available on new type
*/
func main() {
	x := Football{&Ball{Radius: 1, Material: "Material"}}
	//x.Material = "MaterialX"
	x.Bounce() // This will case panic if Ball in Football is not initialize to proper address
}
