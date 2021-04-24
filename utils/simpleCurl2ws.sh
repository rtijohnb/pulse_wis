#!/bin/bash -x 
curl -sS --include \
     --http1.1 --no-buffer \
     -H "Connection: Upgrade" \
     -H "Upgrade: websocket" \
     -H "Access-Control-Max-Age: 60" \
     -H "Host: example.com:80" \
     -H "Origin: http://www.example.com" \
     http://example.com:80/
