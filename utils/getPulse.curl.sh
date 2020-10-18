#!/bin/bash
#
HOST=127.0.0.1:9900
APP=PulseWisApp
PARTS=PulseWisParticipant
SUBS=PulseWisSubscriber
READERS=PatiendPulseReader
URL=http://$HOST/dds/rest1/applications/$APP/domain_participants/$PARTS/subscribers=$SUBS/data_readers/$READERS
echo $URL
curl -s -X GET -H "Cache-Control:no-cache" $URL

