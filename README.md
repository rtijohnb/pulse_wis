# pulse_wis

![](https://github.com/psmass/DDSexamples/blob/master/RtiAsOne.png)

Configuration files, related scripts, and web content for the Web Integration Service instance used in the Pulse Demo.
Note that type and QoS definitions are drawn from the `MedicalDemo.xml` file in the pulse_sysdesigner repository via
setting the NDDS_QOS_PROFILES to point to that file.

**Note that in the public demo, the
Web Integration Service (WIS) runs on an AWS instance. A routing service instance (see the pulse_aws_routing repo)
provides a bridge between the Pi used in the demo and this AWS instance/WIS instance.  Please load that and
run it alongside this WIS instance.**

![QR code for WIS instance](/QR.code.50.18.214.8-8090.png)

http://50.18.214.8:8090/

Several script files have been placed in this directory to simplify running the WIS instance.  Configuration of the WIS session is stored in the following file:

`USER_WEB_INTEGRATION_SERVICE.xml` - configuration for the WIS instance described above

Two environment variables must be set appropriately for this service to run correctly, as follows:

NDDSHOME: must be set to the name of the directory where Connext is installed in the host environment. <br>
e.g. for Linux: export NDDSHOME=$(HOME)/rti_connext_dds-6.0.1 <br>
e.g. for Windows: set NDDSHOME=C:\PROGRA~1\rti_connext_dds-6.0.1 <br>

PULSE_DEMO_HOME: must be set to the name of the directory where the pulse repositories have been cloned in. <br>
e.g. for Linux: export PULSE_DEMO_HOME=$(HOME)/repos/Pulse<br>
e.g. for Windows: set PULSE_DEMO_HOME=%HOMEDRIVE%%HOMEPATH%\repos\Pulse <br>

Two script files are in this directory to simplify running the WIS in various environments: <br>
`runPulseWis.sh` - script to start the WIS instance on a Linux host<br>
`runPulseWis.bat` - script to start the Pi WIS instance on a Windows host<br>

To use any of the above scripts, 
1. place the relevant configuration file noted above in a directory
1. make that your working directory
1. run the appropriate script as described above to start the service
