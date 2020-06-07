package main

// Find output of below program
func main() {
	s := "123"
	ps := &s
	b := []byte(*ps) // Note that new instance is created here and not just reference assignment
	pb := &b

	s += "4"
	*ps += "5"
	b[1] = '0'

	println(*ps)
	println(string(*pb))
}
