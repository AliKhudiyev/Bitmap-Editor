#!/bin/bash

echo "Multi-Time Processing or Live Processing is to process an image under the supervision of user."
echo "Current version : 1.0"

echo "Starting the program."
echo

./run "0"

if [ -e __tmp_img_01.bmp ]
then
    rm __tmp_img_01.bmp
fi
