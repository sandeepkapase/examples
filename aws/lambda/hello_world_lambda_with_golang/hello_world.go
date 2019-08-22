package main

import (
	"github.com/aws/aws-lambda-go/lambda"
)

func hello_World() (string, error) {
	return "Hello world lambda", nil
}

func main() {
	lambda.Start(hello_World)
}
