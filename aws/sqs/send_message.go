package main

import (
	"fmt"
	"strconv"
	"time"
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
    msg := "time: " + strconv.FormatInt(time.Now().UnixNano(),10)
	
	// Send message
	send_params := &sqs.SendMessageInput{
		MessageBody:  aws.String(msg), 
		QueueUrl:     aws.String(QueueUrl),       // Required
		DelaySeconds: aws.Int64(3),               // (optional) 傳進去的 message 延遲 n 秒才會被取出, 0 ~ 900s (15 minutes)
	}
	send_resp, err := svc.SendMessage(send_params)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("[Send message] \n%v \n\n", send_resp)
}
