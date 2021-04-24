#!/bin/bash
#
HOST=localhost:8090
curl --silent -i -X OPTIONS $HOST \
-H 'Access-Control-Request-Method: GET' \
-H 'Access-Control-Request-Headers: Content-Type, Accept' \
-H 'Origin: http://localhost:3000'


