#!/bin/bash -
SCRIPT=$(readlink -f $0)
SCRIPTPATH=`dirname $SCRIPT`
source $SCRIPTPATH/data.sh

> $LOGFILE

# create QUEUE
if aws sqs create-queue --queue-name $QUEUE_NAME &>> $LOGFILE
then
    echo Queue created successfully : $QUEUE_NAME
else
    echo Failed to creat Queue : $QUEUE_NAME
fi
