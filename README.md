# pulse_wis

![](https://github.com/psmass/DDSexamples/blob/master/RtiAsOne.png)

Configuration files, related scripts, and web content for the Web Integration Service instance used in the Pulse Demo.

**Note that in the standard demo described on the confluence page related to this demo, the
**Web Integration Service (WIS) runs on an AWS instance. A routing service instance (see pulse_aws_routing repo)
**provides a bridge between the Pi used in the demo and this AWS instance/WIS instance.  Please load that and
**run it alongside this WIS instance.

![QR code for WIS instance](/QR.code.50.18.214.8-8090.png)

http://50.18.214.8:8090/

Several script files have been placed in this directory to simplify running the WIS instance.
In all cases, these scripts assume that the environment variable NDDSHOME is set appropriately for
the host.

Configuration file is as follows:

USER_WEB_INTEGRATION_SERVICE.xml - configuration for the WIS instance described above.

Two script files have been placed in this directory to simplify running the WIS in various environments
as follows:

"linuxStartWis" - one-line script that can be used to start the WIS instance on a linux host.
"RunPulseWis.bat" - one-line script that can be used to start the Pi WIS instance on a windows host.

to use any of the above scripts, place the relevant configuration file noted above in a directory, then
make that your working directory, then run the appropriate script as described above to start the service.
