#!/bin/bash -
SCRIPT=$(readlink -f $0)
SCRIPTPATH=`dirname $SCRIPT`
source $SCRIPTPATH/data.sh

# delete queue
QURL=$(aws sqs list-queues 2> /dev/null | grep $QUEUE_NAME | cut -d\" -f2)
if [[ -z "$QURL" ]] ; then
    echo Queue url not found;
else
    if aws sqs delete-queue --queue-url $QURL  &>> $LOGFILE
    then
        echo Queue deleted successfully: $QUEUE_NAME
    else
        echo Failed to delete Queue: $QUEUE_NAME
    fi
fi

echo Logfile: $LOGFILE
