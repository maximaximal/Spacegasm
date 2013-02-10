#!/bin/bash

#Copy all the libs from /Data/Libraries_linux64 to /usr/lib
read -p "Install precompiled libs to /usr/lib/ (y/n)?"
[ "$REPLY" == "y" ] && sudo cp -r ../Data/Libraries_linux64/* /usr/lib/;

#Install required packages
read -p "Install libenet-dev (y/n)?"
[ "$REPLY" == "y" ] && sudo apt-get install libenet-dev;
read -p "Install libsigc++-2.0-dev (y/n)?"
[ "$REPLY" == "y" ] && sudo apt-get install libsigc++-2.0-dev;
read -p "Install libpq-dev (y/n)?"
[ "$REPLY" == "y" ] && sudo apt-get install libpq-dev;
read -p "Install postgresql (y/n) (this starts a background user at system startup - PostgreSQL!) ?"
[ "$REPLY" == "y" ] && sudo apt-get install postgresql;

#Echo success message
echo "Succefully installed the tibraries!";
