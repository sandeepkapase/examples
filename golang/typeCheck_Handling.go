package main

import "fmt"
import "errors"
import "context"
import "github.com/aws/aws-lambda-go/events"

//import "reflect"

//import "github.com/aws/aws-lambda-go/lambda"

func main() {
	var reqa events.APIGatewayProxyRequest
	var reqb events.ALBTargetGroupRequest
	var reqc events.SQSEvent
	var reqd interface{}
	handler(context.Background(), reqa)
	handler(context.Background(), reqb)
	handler(context.Background(), reqc)
	handler(context.Background(), reqd)
}

func handler(ctx context.Context, req interface{}) error {

	if req == nil {
		return errors.New("empty request")
	}

	switch req.(type) {
	case events.APIGatewayProxyRequest:
		fmt.Println("Handling:APIGatewayProxyRequest:")
	case events.ALBTargetGroupRequest:
		fmt.Println("Handling:ALBTargetGroupRequest")
	case events.SQSEvent:
		fmt.Println("Handling:SQSEvent")
	default:
		fmt.Println("Unknow Request")
		return errors.New("Unknow Request")
	}

	return nil

	/*fmt.Println(reflect.TypeOf(req).PkgPath(), reflect.TypeOf(req).Name())
	fmt.Println(reflect.TypeOf(req).String())*/
}
