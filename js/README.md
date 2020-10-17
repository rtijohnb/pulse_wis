# Web Shapes/Pulse Demo
Currently this is a blend of ShapesDemo: ``http://localhost:8080/js/`` and the start of pulse demo
``http://localhost:8080/``. It illustrates how to subscribe to Shape topics using _RTI Web
Integration Service_. The samples read are drawn on a Canvas using Fabric—a simple JavaScript framework.

![Alt text](../../../resources/img/rti_web_shapes_demo_screenshot.png "Web Shapes Demo Screenshot")

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
Example: ``http://<hostname>:8080``. This specific example can then be found
under ``http://<hostname>:8080/js``. If the ``-documentRoot`` is set to say 
``~/`` and your pages start in location ``~/Gitub/pulse_wis``,  then the specific
example would be under ``http://<hostname>:8080/Github/pulse_wis/js``
* The ``-enablekeepAlive`` argument configures the service to keep open the
underlying TCP connection between client and server between subsequent requests
and responses when possible.

### Running RTI Shapes Demo
Once you have started _Web Integration Service_, you can open _RTI Shapes
Demo_ and start publishing shapes.

### Running Simple Shapes Demo JavaScript Client
Open a browser and navigate to
``http://<hostname>:8080/examples/simple_shapes_demo/js``. You will find
there all the shapes that are being published.
