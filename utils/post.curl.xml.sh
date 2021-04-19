#!/bin/bash -x
#
URL="http://localhost:8090/dds/v1/websocket_connections"
curl -sS -X POST \
	-H "Content-Type:application/dds-web+xml" \
	-H "Accept:application/dds-web+xml" \
	-H "Cache-Control:no-cache" \
	-d '<name>curlxml_pulse_data_ws</name>' \
	$URL

