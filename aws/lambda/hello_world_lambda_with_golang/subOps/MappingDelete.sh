#!/bin/bash -
SCRIPT=$(readlink -f $0)
SCRIPTPATH=`dirname $SCRIPT`
source $SCRIPTPATH/data.sh

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

echo Logfile: $LOGFILE
