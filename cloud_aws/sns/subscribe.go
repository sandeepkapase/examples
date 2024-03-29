package main

import (
	"fmt"
	"github.com/aws/aws-sdk-go/aws"
	"github.com/aws/aws-sdk-go/aws/credentials"
	"github.com/aws/aws-sdk-go/aws/session"
	"github.com/aws/aws-sdk-go/service/sns"
	"os"
)

const httpEndpoint = "http://ec2-100-25-10-35.compute-1.amazonaws.com"
const httpProtocol = "http"
const snsTopicARN = "arn:aws:sns:us-east-1:361108732765:"

var awsRegion = "us-east-1"
var endpoint = ""

var ak = os.Getenv("AWS_ACCESS_KEY_ID")
var sk = os.Getenv("AWS_SECRET_ACCESS_KEY")

//subscribe sends a subscribe request to SNS topic and initiates the subscritption process
func subscribe(endPoint string, protocol string, topicARN string) {

	cfg := aws.Config{}
	cfg.Region = &awsRegion
	cfg.Endpoint = &endpoint
	cfg.Credentials = credentials.NewStaticCredentials(ak, sk, "")

	input := &sns.SubscribeInput{
		Endpoint: &endPoint,
		Protocol: &protocol,
		TopicArn: &topicARN,
	}

	//sess, err := session.NewSession(&aws.Config{Region: aws.String(getenv("AWS_REGION", awsRegion))})
	sess, err := session.NewSession(&cfg)
	if err != nil {
		fmt.Printf("Unable to initiate session")
		return
	}
	svc := sns.New(sess)

	out, err := svc.Subscribe(input)
	if err != nil {
		fmt.Println("Unable to Subscribe")
		return
	}
	fmt.Printf(*out.SubscriptionArn)
}

//getenv returns env varibale if set otherwise returns default value
func getenv(key, defaultValue string) string {
	value := os.Getenv(key)
	if len(value) == 0 {
		return defaultValue
	}
	return value
}

func main() {
	httpEndpoint := getenv("HTTP_ENDPOINT", httpEndpoint)
	httpProtocol := getenv("HTTP_PROTOCOL", httpProtocol)

	if len(os.Args) != 2 {
		fmt.Println("Topic name expected")
		return
	}
	fmt.Println(os.Args[1])
	snsTopicARN := getenv("SNS_TOPIC_ARN", snsTopicARN+os.Args[1])

	subscribe(httpEndpoint, httpProtocol, snsTopicARN)
}
