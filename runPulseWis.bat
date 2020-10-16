@echo off
"%NDDSHOME%/bin/rtiwebintegrationservice.bat" ^
  -cfgName PulseWis ^
  -enableKeepAlive yes ^
  -documentRoot .
