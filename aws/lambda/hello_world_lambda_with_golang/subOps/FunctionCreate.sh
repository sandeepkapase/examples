#!/bin/bash -
SCRIPT=$(readlink -f $0)
SCRIPTPATH=`dirname $SCRIPT`
source $SCRIPTPATH/data.sh

> $LOGFILE

############################## CREATE PART ##############################################
# create function
cd ! $SCRIPTPATH/.. && { echo Failed to lambda src dir ; exit -1 ; }
pwd
rm main &> /dev/null
export GOOS=linux ; export GOARCH=amd64 ; if ! go build -o main hello_world.go &>> /dev/null ; then echo go build failed ; exit -1 ; fi
if ! zip -j main.zip main &>> /dev/null ; then echo Create zip failed ; exit -1; fi

if aws lambda create-function --function-name $FUNCTION_NAME --runtime go1.x --role arn:aws:iam::361108732765:role/service-role/DCP_SDK_AuditOpsRole --handler main --zip-file fileb://./main.zip  &>> $LOGFILE
then
    echo Function Created Successfully $FUNCTION_NAME
else
    echo Failed to Create function $FUNCTION_NAME
fi

# invoke function
aws lambda invoke --function-name $FUNCTION_NAME out.json --log-type Tail &>> $LOGFILE
echo Lambda Function output:
cat out.json

echo Logfile: $LOGFILE
