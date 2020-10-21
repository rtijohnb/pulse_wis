#!/bin/bash
#
HOST=127.0.0.1:9900
APP=PulseWisApp
PARTS=PulseWisParticipant
SUBS=PulseWisSubscriber
READERS=PatientPulseReader
# URL=http://$HOST/dds/rest1/applications
# URL=http://$HOST/dds/rest1/applications/$APP/domain_participants
# URL=http://$HOST/dds/rest1/applications/$APP/domain_participants/$PARTS/topics
# URL=http://$HOST/dds/rest1/applications/$APP/domain_participants/$PARTS/subscribers
URL=http://$HOST/dds/rest1/applications/$APP/domain_participants/$PARTS/subscribers/$SUBS/data_readers/$READERS?prettyPrint="true"
echo $URL
curl -s -X GET -H "Cache-Control:no-cache" $URL

