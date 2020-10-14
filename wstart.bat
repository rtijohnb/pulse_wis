@echo off
"%NDDSHOME%/bin/rtiwebintegrationservice.bat" ^
  -cfgFile "simple_shapes_demo.xml" ^
  -cfgName simpleShapesDemo ^
  -enableKeepAlive yes ^
  -documentRoot .
