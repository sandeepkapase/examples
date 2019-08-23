package main

import (
	"context"
	"fmt"
	"log"
	"math/rand"
	"net/http"
	"time"

	"github.com/aws/aws-sdk-go/aws"
	"github.com/aws/aws-sdk-go/aws/session"
	"github.com/aws/aws-sdk-go/service/sns"
	"github.com/aws/aws-sdk-go/service/sqs"
)

func main() {
	if err := makeTopicAndQueue(); err != nil {
		log.Fatalf("aws-sns-sqs: %v", err)
	}
}

func makeTopicAndQueue() error {
	// Create new session
	sess, err := session.NewSession(&aws.Config{
		HTTPClient:  &http.Client{},
		Region:      aws.String("us-east-2"),
		Credentials: nil,
		MaxRetries:  aws.Int(0),
	})

	// Create SNS Topic related to AT event
	log.Printf("Creating an SNS topic")
	topicName := "ATeventX"
	snsClient := sns.New(sess, &aws.Config{})
	out, err := snsClient.CreateTopic(&sns.CreateTopicInput{Name: aws.String(topicName)})
	if err != nil {
		return fmt.Errorf(`creating topic "%s": %v`, topicName, err)
	}

	// Create SQS
	subName := "ATQueue"
	log.Printf("Creating an SQS queue")
	sqsClient := sqs.New(sess, &aws.Config{})
	out2, err := sqsClient.CreateQueue(&sqs.CreateQueueInput{QueueName: aws.String(subName)})
	if err != nil {
		return fmt.Errorf(`creating subscription queue "%s": %v`, subName, err)
	}

	// subscribe for queue to SNS topic
	log.Printf("Getting queue ARN")
	out3, err := sqsClient.GetQueueAttributes(&sqs.GetQueueAttributesInput{
		QueueUrl:       out2.QueueUrl,
		AttributeNames: []*string{aws.String("QueueArn")},
	})
	if err != nil {
		return fmt.Errorf("getting queue ARN for %s: %v", *out2.QueueUrl, err)
	}
	qARN := out3.Attributes["QueueArn"]

	log.Printf("Subscribing the queue to the topic")
	subResp, err := snsClient.Subscribe(&sns.SubscribeInput{
		Attributes: map[string]*string{"RawMessageDelivery": aws.String("true")},
		TopicArn:   out.TopicArn,
		Endpoint:   qARN,
		Protocol:   aws.String("sqs"),
	})
	if err != nil {
		return fmt.Errorf("subscribing: %v", err)
	}
	log.Printf("Subscription arn: '%s'", *subResp.SubscriptionArn)

	// Send message to SNS topic
	log.Printf("Sending a message to the topic")
	msg := fmt.Sprintf("sns/sqs test. random number: %d", rand.Int())
	ctx := context.Background()
	_, err = snsClient.PublishWithContext(ctx, &sns.PublishInput{
		Message:  aws.String(msg),
		TopicArn: out.TopicArn,
	})
	if err != nil {
		return fmt.Errorf("publishing: %v", err)
	}

	log.Printf("Getting the queue URL")
	req, resp := sqsClient.GetQueueUrlRequest(&sqs.GetQueueUrlInput{QueueName: aws.String(subName)})
	err = req.Send()
	if err != nil {
		return fmt.Errorf("getting queue URL: %v", err)
	}
	log.Printf("Queue URL: %s", *resp.QueueUrl)

	for _ = range time.Tick(time.Second) {
		log.Printf("Receiving the message from the queue")
		max := int64(10)
		output, err := sqsClient.ReceiveMessageWithContext(ctx, &sqs.ReceiveMessageInput{
			QueueUrl:            resp.QueueUrl,
			MaxNumberOfMessages: aws.Int64(max),
		})
		if err != nil {
			return fmt.Errorf("receiving message: %v", err)
		}
		for _, m := range output.Messages {
			log.Printf("Got message %s", *m.Body)
			log.Printf("Stopping")
			return nil
		}
	}

	return nil
}
