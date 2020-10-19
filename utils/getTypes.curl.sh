#!/bin/bash
#
HOST=127.0.0.1:8080
curl -s -X GET -H "Cache-Control:no-cache" http://$HOST/dds/rest1/types

