package main

import "fmt"

////////////////// ACTUAL DATA AND INTERFACE ////////////////////////////////////
type CallAPiI interface {
	callSquareAPI() int
}
type CallApiData struct {
	data int
}

func (t CallApiData) callSquareAPI() int {
	return t.data * t.data // actual external call
}

////////////////// MOCK   DATA AND INTERFACE ////////////////////////////////////
type MockCallAPiI interface {
	callSquareAPI() int
}

type MockCallApiData struct {
	// No no data here i.e. only exact api signature should be implemented for datatype
}

func (t MockCallApiData) callSquareAPI() int {
	return 100 // mock implemented call
}

type Mock interface {
	add(int, int) int
}

func main() {
	//actualStruct := CallApiData{data: 25}
	fmt.Println("Actual Call", callAPI(CallApiData{data: 25}))
	fmt.Println("Actual Call", callAPI(MockCallApiData{}))
}

// Here we can pass datatype that implements method given in CallAPiI
// So, we define mock interface MockCallAPiI with exact methods in CallAPiI and define mock datatype
// and implement methods in CallAPiI/MockCallAPiI
// So, depending on what object we are passing, methods from actual or mocked interface will gets called
//
// In SHORT, INTERFACE NAME, DATATYPE NAME CAN BE ANYTHING BUT WE NEED TO IMPLEMENT SAME API NAME, SIGNATURE FOR THEM
func callAPI(api CallAPiI) int {
	return api.callSquareAPI()
}
