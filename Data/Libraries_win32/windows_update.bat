@echo off
echo ########################################
echo SFML Sidescroller - Windows Updater
echo Updater was included in Version V0.06
echo Last Update of this Script: V0.06
echo ########################################
echo Please report all kinds of bugs to 
echo bugs.srcttp.org! 
echo ########################################
echo The updater will replace all files of
echo your old installation with the new, 
echo downloaded files. 
echo ########################################
echo Wait for 2 seconds (let the program close)
Data\Libraries_win32\sleep.exe 2
echo Starting the update process....
echo Extracting the new files from the archive....
Data\Libraries_win32\7za.exe x update_win.zip -y
echo Deleting the old update archive...
DEL update_win.zip
echo Finished updating!
echo ########################################
echo Succefully finished updating!
echo Starting the game...
Data\Libraries_win32\sleep.exe 1
"SFML Sidescroller.exe";
exit
exit