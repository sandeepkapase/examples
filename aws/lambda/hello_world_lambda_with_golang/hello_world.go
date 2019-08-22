package main

import (
	"fmt"
	"github.com/aws/aws-lambda-go/lambda"
)

func hello_World() (string, error) {
	fmt.Printf("FHello world lambda")
	return "RHello world lambda", nil
}

func main() {
	lambda.Start(hello_World)
}
