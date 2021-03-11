# py_writer

A data generator for experimenting with rendering known data values.
`writer.py` is a Python DDS Connector application that publishes a simple rising/falling sequence.  It gets the Topic name, publisher and domain from the `pulse.xml` file.

<br>
It is a replacement for pulse playback or live pulse data just for testing.  <br>
`writer.py` depends on rticonnextdds_connector available at: https://github.com/rticommunity/rticonnextdds-connector-py
