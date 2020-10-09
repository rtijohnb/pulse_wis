#!/usr/bin/env python
import argparse
from datetime import datetime
import json
import random
import socket
import time

from flask import Flask, Response, render_template

application = Flask(__name__)
random.seed()  # Initialize the random number generator

### Routes ###
@application.route('/')
def index():
    return render_template('index.html')

@application.route('/chart1')
def chart1():
    return render_template('chart-data-1-per-second.html')

@application.route('/chart10')
def chart10():
    return render_template('chart-data-10-per-second.html')

@application.route('/chart100')
def chart100():
    return render_template('chart-data-100-per-second.html')

### Data synthesis ###
hb_values = [
    40, 48, 50, 48, 51, 55, 57, 60, 63, 70, 77, 85, 95,
    85, 77, 70, 63, 60, 57, 55, 51, 48, 40
]
def generate_hb(sleep_interval):
    """generator for heartbeat data"""
    ix = 0
    while True:
        time_now = datetime.now()
        time_val = time_now.strftime('%M:%S')
        json_data = json.dumps({
            'time': time_val,
            'value': hb_values[ix]
        })
        yield f"data:{json_data}\n\n"
        ix += 1
        if ix >= len(hb_values):
            ix = 0
        time.sleep(sleep_interval)

def generate_random_data(sleep_interval):
    """generator for random value data"""
    while True:
        time_now = datetime.now()
        if sleep_interval == 1:
            time_val = time_now.strftime('%M:%S')
        else:
            time_val = time_now.strftime('%M:%S:%f')[:-3]
        json_data = json.dumps({
            'time': time_val,
            'value': random.random() * 100
        })
        yield f"data:{json_data}\n\n"
        time.sleep(sleep_interval)

### Responses ###
@application.route('/chart-data-1-per-second')
def chart_data_1_per_sec():
    return Response(generate_random_data(1), mimetype='text/event-stream')

@application.route('/chart-data-10-per-second')
def chart_data_10_per_sec():
    return Response(generate_hb(0.10), mimetype='text/event-stream')

@application.route('/chart-data-100-per-second')
def chart_data_100_per_sec():
    return Response(generate_random_data(0.040), mimetype='text/event-stream')

### Command line ###
def get_ip():
    """return the routable IP"""
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        # doesn't have to be reachable
        s.connect(('10.255.255.255', 1))
        ip = s.getsockname()[0]
    except Exception:
        ip = '127.0.0.1'
    finally:
        s.close()
    return ip

def process_args():
    """return the parsed cmdline arg namespace"""
    parser = argparse.ArgumentParser(
        description="Start a simple webserver with Flask"
    )
    default_host = get_ip()
    default_port = '9900' # for AWS
    parser.add_argument('-p', '--port', default=default_port,
            help=f'override port of {default_port}')
    parser.add_argument('--host', default=default_host,
            help=f'override host of {default_host}')
    args = parser.parse_args()
    return args
    
if __name__ == '__main__':
    args = process_args()
    #print(f"starting on {args.host}:{args.port}")
    application.run(host=args.host, port=args.port, debug=True, threaded=True)


