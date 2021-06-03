#!/usr/bin/env python
import rticonnextdds_connector as rti
from time import sleep
import sys

SLEEP = float(sys.argv[1]) if len(sys.argv) > 1 else 0.1
with rti.open_connector("MyParticipantLibrary::MyPubParticipant", 'pulse.xml') as connector:
    output = connector.get_output("MyPublisher::MyPulseWriter")

    # print("Waiting for subscriptions...", output)
    # output.wait_for_subscriptions()

    output.instance.set_string("Id.Id", "Herman")
    lohi = [i for i in range(100,200)]
    hilo = lohi[::-1] 
    for i in range(1, 10000):
        bpm = i % 100
        
        output.instance.set_number("bpm", bpm)
        output.instance.set_number("timestamp", i)
        data = lohi if i %2 == 0 else hilo
        output.instance.set_dictionary({"readings": data})

        output.write()
        print(f"  wrote bpm: {bpm} ts: {i}")
        sleep(SLEEP)

    print("Exiting...")
    output.wait() # Wait for all subscriptions to receive the data before exiting
