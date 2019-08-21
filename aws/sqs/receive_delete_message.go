package main

import (
	"fmt"
	"log"
	"github.com/aws/aws-sdk-go/aws"
	"github.com/aws/aws-sdk-go/aws/credentials"
	"github.com/aws/aws-sdk-go/aws/session"
	"github.com/aws/aws-sdk-go/service/sqs"
)

const (
	QueueUrl    = "https://sqs.us-east-1.amazonaws.com/361108732765/dcp_sdk_sns_at"
	Region      = "us-east-1"
	CredPath    = "/home/sandeepk/.aws/credentials"
	CredProfile = "default"
)

func main() {

	sess := session.New(&aws.Config{
		Region:      aws.String(Region),
		Credentials: credentials.NewSharedCredentials(CredPath, CredProfile),
		MaxRetries:  aws.Int(5),
	})

	svc := sqs.New(sess)

	// Receive message
	receive_params := &sqs.ReceiveMessageInput{
		QueueUrl:            aws.String(QueueUrl),
		MaxNumberOfMessages: aws.Int64(3),
		VisibilityTimeout:   aws.Int64(20),
		WaitTimeSeconds:     aws.Int64(5),
	}
	receive_resp, err := svc.ReceiveMessage(receive_params)
	if err != nil {
		fmt.Printf("Error returned by sqs: %v", err)
		log.Println(err)
		return
	}

	mlen := len(receive_resp.Messages)
	if (mlen < 1) {
		fmt.Println("No message found on queue")
		return
	}
	fmt.Printf("[Receive message] \n%v \n\n", receive_resp)

	// Delete message
	for _, message := range receive_resp.Messages {
		delete_params := &sqs.DeleteMessageInput{
			QueueUrl:      aws.String(QueueUrl),  // Required
			ReceiptHandle: message.ReceiptHandle, // Required

		}
		_, err := svc.DeleteMessage(delete_params) // No response returned when successed.
		if err != nil {
			log.Println(err)
		}
		fmt.Printf("[Delete message] \nMessage ID: %s has beed deleted.\n\n", *message.MessageId)
	}
}
