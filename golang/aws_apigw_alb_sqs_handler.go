package main

import "errors"
import "context"
import "github.com/aws/aws-lambda-go/events"

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
		APIGatewayHandler(ctx, req.(events.APIGatewayProxyRequest))
	case events.ALBTargetGroupRequest:
		ALBHandler(ctx, req.(events.ALBTargetGroupRequest))
	case events.SQSEvent:
		SQSHandler(ctx, req.(events.SQSEvent))
	default:
		return errors.New("Unknow Request")
	}

	return nil
}

func APIGatewayHandler(ctx context.Context, req events.APIGatewayProxyRequest) error {
	return nil
}

func ALBHandler(ctx context.Context, req events.ALBTargetGroupRequest) error {
	return nil
}

func SQSHandler(ctx context.Context, req events.SQSEvent) error {
	return nil
}
