#!/bin/bash

echo "Single-Time Processing is to process an action without the supervision of user."
echo "Current version : 1.0"
echo
echo "Starting the program."
echo

./run "1"

if [ -e __tmp_img_01.bmp ]
then
    rm __tmp_img_01.bmp
fi
