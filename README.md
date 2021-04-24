# pulse_wis

![](https://github.com/psmass/DDSexamples/blob/master/RtiAsOne.png)

Configuration files, related scripts, and web content for the Web Integration Service instance used in the Pulse Demo.
Note that type and QoS definitions are drawn from the MedicalDemo.xml file in the pulse_sysdesigner repository via
setting the NDDS_QOS_PROFILES to point to that file.

**Note that in the standard demo described on the confluence page related to this demo, the
**Web Integration Service (WIS) runs on an AWS instance. A routing service instance (see pulse_aws_routing repo)
**provides a bridge between the Pi used in the demo and this AWS instance/WIS instance.  Please load that and
**run it alongside this WIS instance.

![QR code for WIS instance](/QR.code.50.18.214.8-8090.png)

http://50.18.214.8:8090/

Several script files have been placed in this directory to simplify running the WIS instance.  Configuration
of the WIS session is stored in the following file:

USER_WEB_INTEGRATION_SERVICE.xml - configuration for the WIS instance described above.

Two environment variables must be set appropriately for this service to run correctly, as follows:

NDDSHOME: must be set to the name of the directory where connext is installed in the host environment.
e.g. for linux: export NDDSHOME=/home/kenm/rti_connext_dds-6.0.1
e.g. for Windows: setx NDDSHOME C:\RTI\rti_connext_dds-6.0.1 /m

PULSE_DEMO_HOME: must be set to the name of the directory where the pulse repositories have been cloned in.
e.g. for linux: export PULSE_DEMO_HOME=/home/kenm/repos/Pulse
e.g. for Windows: setx PULSE_DEMO_HOME C:\users\kenm\repos\Pulse /m

Two script files have been placed in this directory to simplify running the WIS in various environments
as follows:

"linuxStartWis" - script that can be used to start the WIS instance on a linux host.
"runPulseWis.bat" - one-line script that can be used to start the Pi WIS instance on a windows host.
"runPulseWisWebSockets.bat" - start the WebSocket implementation (requires 6.1.0)

to use any of the above scripts, place the relevant configuration file noted above in a directory, then
make that your working directory, then run the appropriate script as described above to start the service.
