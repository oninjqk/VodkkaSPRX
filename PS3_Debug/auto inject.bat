@echo off
echo user anonymous> ftpcmd.dat
echo anonymous>> ftpcmd.dat
echo bin>> ftpcmd.dat
echo cd /dev_hdd0/tmp/>> ftpcmd.dat
echo put ModMenuV.sprx>> ftpcmd.dat
echo quit>> ftpcmd.dat
ftp -n -s:ftpcmd.dat 192.168.137.99
del ftpcmd.dat
PAUSE