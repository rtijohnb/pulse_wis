# pulse_wis

Currently this branch holds three pages for demo:
(Incremental developement)

-    localhost:port/         <--- The final display of pulse topic on chart js. (not working - same as Localhost:port/shapes/) 
                                - Start WIS with USER_WEB_INTEGRATION_SERVICE.xml

Current State: of localhost:port/ route
- Recorded Data Dave Seltz provided is running through Ken's WIS config. Correct BPM is displayed on the banner and other data is logged to the console (I.e. we can read actual Patient Pulse and Info topics)

- I had attempted to massage Dave's data to add patient ID and varying BPM but that does not seem to work.


## Running the Example
To run this example, execute _Web Integration Service_, _RTI Shapes Demo_, and
the JavaScript client as follows.

### Running Web Integration Service
To run the example, open a terminal and enter the following command:

From any directory:
```
$NDDSHOME/bin/rtiwebintegrationservice \
  -cfgFile ~/path_to_xml/simple_shapes_demo.xml \
  -cfgName simpleShapesDemo \
  -enableKeepAlive yes \
  -listeningPorts 9900\
  -documentRoot ~/path to index.html for ``http://<hostname>:8080``
```
Example:
$NDDSHOME/bin/rtiwebintegrationservice-cfgFile ~/GitHub/pulse_wis/simple_shapes_demo.xml -cfgName simpleShapesDemo  -enableKeepAlive yes -documentRoot ~/GitHub/pulse_wis/

Where:

* The ``-cfgFile`` argument loads the appropriate configuration file
into _Web Integration Service_.
* The ``-cfgName`` argument specifies the configuration to be instantiated—in
this case ```SimpleShapesDemo```—which starts the ``SimpleShapesDemoApp``.
This application instantiates a _DomainParticipant_ with _DataReaders_ to read
to all shape topics (i.e., Squares, Circles, and Triangles).
* The ``-documentRoot`` argument specifies the folder that _Web
Integration Service's_ web server will provide when accessing the 
default & Top Level URL (must be top level or the specific webpage must be
included in the URL)
Example: ``http://<hostname>:port``. This specific example can then be found
under ``http://<hostname>:port/js``. If the ``-documentRoot`` is set to say 
``~/`` and your pages start in location ``~/Gitub/pulse_wis``,  then the specific
example would be under ``http://<hostname>:port/Github/pulse_wis/js``
* The ``-enablekeepAlive`` argument configures the service to keep open the
underlying TCP connection between client and server between subsequent requests
and responses when possible.


### To Replay Pulse Data on Domain 0 to WIS
From the directory with the USER_REPLAY_SERVICE.xml file (e.g., ~/Github/pulse_wis):
 /Applications/rti_connext_dds-6.0.1/bin/rtireplayservice -cfgName PlayHeart -verbosity 3 -DRATE=1.0

 Note: File ./USER_REPLAY_SERVICE.xml is pulled in by default

