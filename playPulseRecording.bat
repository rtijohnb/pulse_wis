@echo off
"%NDDSHOME%/bin/rtireplayservice.bat" ^
  -cfgName PlayPulse -verbosity 3 ^
  -DRATE=10.0 -domainIdBase 20
