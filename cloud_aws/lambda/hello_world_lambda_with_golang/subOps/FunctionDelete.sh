#!/bin/bash -
SCRIPT=$(readlink -f $0)
SCRIPTPATH=`dirname $SCRIPT`
source $SCRIPTPATH/data.sh

# delete lambda function
if ! aws lambda delete-function --function-name $FUNCTION_NAME &>> $LOGFILE
then
    echo failed to  delete function $FUNCTION_NAME
else
    echo Deleted function: $FUNCTION_NAME
fi

echo Logfile: $LOGFILE
