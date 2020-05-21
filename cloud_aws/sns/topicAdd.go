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

var awsRegion = "us-east-1"
var endpoint = ""

var ak = os.Getenv("AWS_ACCESS_KEY_ID")
var sk = os.Getenv("AWS_SECRET_ACCESS_KEY")

//subscribe sends a subscribe request to SNS topic and initiates the subscritption process
func topicAdd(topicName string) {

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

	resp, err := svc.CreateTopic(&sns.CreateTopicInput{Name: &topicName})
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
	if len(os.Args) != 2 {
		fmt.Println("Topic name expected")
		return
	}
	fmt.Println(os.Args[1])
	topicAdd(os.Args[1])
}
