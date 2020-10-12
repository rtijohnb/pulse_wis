#!/usr/bin/env python
import argparse
from datetime import datetime
from itertools import cycle
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

@application.route('/chart60')
def chart60():
    return render_template('chart-data-60-per-second.html')

@application.route('/chart100')
def chart100():
    return render_template('chart-data-100-per-second.html')

@application.route('/history')
def history():
    return render_template('history-chart.html')

### Data synthesis ###
def generate_ecg(sleep_interval):
    """generator for heartbeat data"""
    hb_values = []
    with open('ecg_dataAll.txt', 'r') as ecg:
        for row in ecg:
            hb_values.append(float(row))
    for item in cycle(hb_values):
        json_data = json.dumps({
            'value': item 
        })
        yield f"data:{json_data}\n\n"
        time.sleep(sleep_interval)
### Data synthesis ###
def generate_hb(sleep_interval):
    """generator for heartbeat data - single file, not used"""
    hb_values = {}
    with open('ecg_data01.txt', 'r') as ecg:
        next(ecg); next(ecg)
        for row in ecg:
            one, two = row.split()
            hb_values[one] = two
    for item in cycle(hb_values.items()):
        json_data = json.dumps({
            'time': item[0],
            'value': float(item[1]) 
        })
        yield f"data:{json_data}\n\n"
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
            #'time': time_val,
            'value': (random.random() * 100) - 50
        })
        yield f"data:{json_data}\n\n"
        time.sleep(sleep_interval)

### Responses ###
@application.route('/chart-data-1-per-second')
def chart_data_1_per_sec():
    return Response(generate_random_data(1), mimetype='text/event-stream')

@application.route('/chart-data-60-per-second')
def chart_data_60_per_sec():
    return Response(generate_ecg(0.0166666), mimetype='text/event-stream')

@application.route('/chart-data-100-per-second')
def chart_data_100_per_sec():
    return Response(generate_random_data(0.01), mimetype='text/event-stream')

@application.route('/history-response')
def history_response():
    return Response(generate_random_data(0.010), mimetype='text/event-stream')

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
    application.run(host=args.host, port=args.port, debug=True, threaded=True)


