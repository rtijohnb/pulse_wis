#!/bin/bash -x
#
URL="http://localhost:8090/dds/v1/websocket_connections"
curl -sS -X POST -H "Content-Type:application/dds-web+json" \
	-H "Accept:application/dds-web+json" \
	-d '{"name": "curl_pulse_data_ws" }' \
	$URL

