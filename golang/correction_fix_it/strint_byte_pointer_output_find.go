package main

// Find output of below program
func main() {
	s := "123"
	ps := &s
	b := []byte(*ps) // Not that new instance is created here and not just reference
	pb := &b

	s += "4"
	*ps += "5"
	b[1] = '0'

	println(*ps)
	println(string(*pb))
}
