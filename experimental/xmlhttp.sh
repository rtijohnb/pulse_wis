#!/bin/bash

curl -X GET -H "Cache-Control: no-cache" -H "X-Requested-With: XMLHttpRequest" http://localhost:8090/dds/rest1/types -H "Origin: http://localhost:12345" -v
