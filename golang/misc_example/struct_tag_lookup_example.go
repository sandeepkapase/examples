package main

import "fmt"
import "reflect"

type T struct {
	f string `one:"1" two:"2"blank:""`
	k string `json:"name,omitempty" two:"2"blank:""`
}

func main() {
	t := reflect.TypeOf(T{})
	f, _ := t.FieldByName("f")
	fmt.Println(f.Tag) // one:"1" two:"2"blank:""

	k, _ := t.FieldByName("k")
	fmt.Println(k.Tag) // one:"1" two:"2"blank:""

	v, ok := f.Tag.Lookup("one")
	fmt.Printf("%s, %t\n", v, ok) // 1, true

	v, ok = f.Tag.Lookup("two")
	fmt.Printf("%s, %t\n", v, ok) // 1, true

	v, ok = f.Tag.Lookup("blank")
	fmt.Printf("%s, %t\n", v, ok) // , true
	v, ok = f.Tag.Lookup("five")
	fmt.Printf("%s, %t\n", v, ok) // , false
}
