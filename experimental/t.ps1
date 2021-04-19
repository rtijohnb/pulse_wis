param (
    [string]$sys_designer = pulse_sysdesigner,
    [string]$NDDS_QOS_PROFILES = $env:SYS_DESIGNER,
    [string]$WIS_HTTP_PORT = 8090,
    [string]$WIS_XML = LOCAL_WEB_INTEGRATION_SERVICE.xml
)

write-output "sys is $SYS_DESIGNER"
write-output "nqp is $NDDS_QOS_PROFILES "
write-output "wp: $WIS_HTTP_PORT "
write-output "xml is $WIS_XML "

