#!/bin/bash -
SCRIPT=$(readlink -f $0)
SCRIPTPATH=`dirname $SCRIPT`
source $SCRIPTPATH/subOps/data.sh

# ==> delete lambda,queue,mapping
# ==> create lambda,queue,mapping


############################## DELETE PART ##############################################
# delete lambda mapping
MAP_UUID=$(aws lambda list-event-source-mappings  --function-name $FUNCTION_NAME 2> /dev/null | grep UUID | cut -d\" -f4)
if [[ -z "$MAP_UUID" ]] ; then
    echo no function mapping found ;
else
    if ! aws lambda delete-event-source-mapping --uuid $MAP_UUID &>> $LOGFILE
    then
        echo failed to delete mapping with uuid : $MAP_UUID
    else
        echo Deleted mapping for : $MAP_UUID $FUNCTION_NAME
    fi
fi

# delete lambda function
if ! aws lambda delete-function --function-name $FUNCTION_NAME &>> $LOGFILE
then
    echo failed to  delete function $FUNCTION_NAME
else
    echo Deleted function: $FUNCTION_NAME
fi

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
