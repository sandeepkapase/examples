package main

import (
	"fmt"
	"github.com/aws/aws-sdk-go/aws"
	"github.com/aws/aws-sdk-go/aws/credentials"
	"github.com/aws/aws-sdk-go/aws/session"
	"github.com/aws/aws-sdk-go/service/sns"
	"os"
)

var snsTopicARN = "arn:aws:sns:us-east-1:361108732765:"

var awsRegion = "us-east-1"
var endpoint = ""

var ak = os.Getenv("AWS_ACCESS_KEY_ID")
var sk = os.Getenv("AWS_SECRET_ACCESS_KEY")

//subscribe sends a subscribe request to SNS topic and initiates the subscritption process
func publishMsg(topicName string, message string) {

	cfg := aws.Config{}
	cfg.Region = &awsRegion
	cfg.Endpoint = &endpoint
	cfg.Credentials = credentials.NewStaticCredentials(ak, sk, "")

	sess, err := session.NewSession(&cfg)
	if err != nil {
		fmt.Printf("Unable to initiate session")
		return
	}
	svc := sns.New(sess)

	snsTopicARN = snsTopicARN + topicName
	resp, err := svc.Publish(&sns.PublishInput{
		Message:           &message,
		TopicArn:          &snsTopicARN,
		MessageAttributes: map[string]*sns.MessageAttributeValue{},
	})

	if err != nil {
		fmt.Println("Unable to create Topic: ", err)
		return
	}
	fmt.Printf("Resp: ", resp)
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
	if len(os.Args) != 3 {
		fmt.Println("Topic name and message  expected")
		return
	}
	fmt.Println("\nTopic Name : ", os.Args[1])
	fmt.Println("\nMessage : ", os.Args[2])
	//publishMsg(topicName, message)
	publishMsg(os.Args[1], os.Args[2])
}
