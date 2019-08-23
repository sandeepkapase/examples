#!/bin/bash -
SCRIPT=$(readlink -f $0)
SCRIPTPATH=`dirname $SCRIPT`
source $SCRIPTPATH/data.sh

> $LOGFILE

# create event mapping
if aws lambda create-event-source-mapping --function-name $FUNCTION_NAME --batch-size 1 --event-source-arn arn:aws:sqs:us-east-1:361108732765:$QUEUE_NAME &>> $LOGFILE
then
    echo function queue event mapping done successfully.
else
    echo Failed to create function queue event mapping.
fi

echo Logfile: $LOGFILE
