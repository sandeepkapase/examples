#!/bin/bash -
SCRIPT=$(readlink -f $0)
SCRIPTPATH=`dirname $SCRIPT`
source $SCRIPTPATH/subOps/data.sh

> $LOGFILE

############################## CREATE PART ##############################################
# create function
rm main &> /dev/null
export GOOS=linux ; export GOARCH=amd64 ; if ! go build -o main hello_world.go &>> /dev/null ; then echo go build failed ; exit -1 ; fi
if ! zip -j main.zip main &>> /dev/null ; then echo Create zip failed ; exit -1; fi

if aws lambda create-function --function-name $FUNCTION_NAME --runtime go1.x --role arn:aws:iam::361108732765:role/service-role/DCP_SDK_AuditOpsRole --handler main --zip-file fileb://./main.zip  &>> $LOGFILE
then
    echo Function Created Successfully $FUNCTION_NAME
else
    echo Failed to Create function $FUNCTION_NAME
fi


# create QUEUE
if aws sqs create-queue --queue-name $QUEUE_NAME &>> $LOGFILE
then
    echo Queue created successfully : $QUEUE_NAME
else
    echo Failed to creat Queue : $QUEUE_NAME
fi

# create event mapping
if aws lambda create-event-source-mapping --function-name $FUNCTION_NAME --batch-size 1 --event-source-arn arn:aws:sqs:us-east-1:361108732765:$QUEUE_NAME &>> $LOGFILE
then
    echo function queue event mapping done successfully.
else
    echo Failed to create function queue event mapping.
fi


# invoke function
aws lambda invoke --function-name $FUNCTION_NAME out.json --log-type Tail &>> $LOGFILE
echo Lambda Function output:
cat out.json

echo Logfile: $LOGFILE
