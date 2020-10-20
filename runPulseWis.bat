@echo off
"%NDDSHOME%/bin/rtiwebintegrationservice.bat" ^
  -cfgName PulseWis ^
  -enableKeepAlive yes ^
  -listeningPorts 8080 ^
  -documentRoot .
