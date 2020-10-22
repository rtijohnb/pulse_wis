# pulse_wis

Currently this branch holds three pages for demo:
(Incremental developement)

-    localhost:port/         <--- The final display of pulse topic on chart js. (not working - same as Localhost:port/shapes/) 
                                - Start WIS with USER_WEB_INTEGRATION_SERVICE.xml

Current State: of localhost:port/ route
- Recorded Data Dave Seltz provided is running through Ken's WIS setup to the browser. Showing both the pulse graph as well as the correct BPM.
  (glitches in the data are, well, in the data - chart.js is reflecting correctly - we temperarily installed a simple filter in the browser js to set a pulse value <100 to 500 - this needs to get cleaned up at the  source not the browser).

## Running the Example
To run this example locally, execute _Web Integration Service as described below.
To get data use either a real source or use replay service provided and start it 
as described below.

Note: Domain 20 is used between the "AWS Router Service" and WIS - i.e. the PulseTopic DDS Databus is domain 20. 

### Running Web Integration Service
To run the example, open a terminal and enter the following command:

From any directory:
```
$NDDSHOME/bin/rtiwebintegrationservice \
  -cfgFile ~/path_to_xml/USER_WEB_INTEGRATION_SERVICE.xml\   (not required if starting WIS from a directory with this file)
  -cfgName PulseWis \
  -enableKeepAlive yes \
  -listeningPorts 9900\
  -documentRoot ~/path to index.html for ``http://<hostname>:9900``
```
Example: (from toplevel directory with USER_WEB_INTEGRATION_SERVICE.xml)
$NDDSHOME/bin/rtiwebintegrationservice  -cfgName PulseWis  -enableKeepAlive yes -documentRoot ~/GitHub/pulse_wis/webroot/

Where:

* The ``-cfgFile`` argument loads the appropriate configuration file
into _Web Integration Service_. [this param not required if starting WIS from a directory 
the default name "USER_WEB_INTEGRATION_SERVICE.xml")
* The ``-cfgName`` argument specifies the configuration to be instantiated—in
this case ```PulseWis```—which starts the ``PulseWisApp``.
This application instantiates a _DomainParticipant_ with _DataReaders_ to read
to all shape topics (i.e., Squares, Circles, and Triangles).
* The ``-documentRoot`` argument specifies the folder that _Web
Integration Service's_ web server will provide when accessing the 
default & Top Level URL with the landing page index.html
Example: ``http://<hostname>:port``. This specific example can then be found
under ``http://<hostname>:port``. If the ``-documentRoot`` is set to say 
``~/`` and your pages start in location ``~/Gitub/pulse_wis``,  then the specific
example would be under ``http://<hostname>:port/other_page``
* The ``-enablekeepAlive`` argument configures the service to keep open the
underlying TCP connection between client and server between subsequent requests
and responses when possible.


### To Replay Pulse Data on Domain 20 to WIS
From the directory with the USER_REPLAY_SERVICE.xml file (e.g., ~/Github/pulse_wis):
 /Applications/rti_connext_dds-6.0.1/bin/rtireplayservice -cfgName PlayPulse -verbosity 3 -DRATE=1.0 -domainIdBase 20
 

 Note: File ./USER_REPLAY_SERVICE.xml is pulled in by default 

NOTE:  Domain 20 is used between the "AWS Router Service" and WIS. Replay data was done on domain 0. To use replay data
you need to set the Replay Service <domain_participant name="DefaultParticipant"> <domain_id>0 but add the parameter
-domainIdBase 20 to the replay command line.  To use actual data coming in on domain 20 you won't use replay service and 
therefore the above note does not apply
