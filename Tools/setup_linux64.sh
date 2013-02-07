#!/bin/sh

#Copy all the libs from /Data/Libraries_linux64 to /usr/lib
sudo cp -r ../Data/Libraries_linux64/* /usr/lib/;

#Copy the CEGUI
sudo cp -r ../CEGUI/bin_linux64/* /usr/locales/lib/;

#Echo CEGUI warning (compile yourself!)
echo "It would be smart to download and compuile CEGUI 0.7.9 yourself! The libraries with this package may are not installed in the right way...";

#Install required packages
sudo apt-get install libenet-dev libsigc++-2.0-dev libpq-dev;



#Echo success message
echo "Succefully installed the tibraries!";
