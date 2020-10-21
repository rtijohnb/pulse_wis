@echo off
set WIS_PORTS=9900
echo Listening on %WIS_PORTS%
"%NDDSHOME%/bin/rtiwebintegrationservice.bat" ^
  -cfgName PulseWis ^
  -enableKeepAlive yes ^
  -listeningPorts %WIS_PORTS% ^
  -documentRoot webroot
