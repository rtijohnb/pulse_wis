@echo off
"%NDDSHOME%/bin/rtiwebintegrationservice.bat" ^
  -cfgName PulseWis ^
  -enableKeepAlive yes ^
  -listeningPorts 9900 ^
  -documentRoot .
