#!/bin/bash

echo "Welcome"
read -p 'Is there any image to be processed [y/n]? ' ans

if [ "y" == "$ans" ]
then
    alert=0
    while [ $alert -lt 3 ]
    do
        read -p 'Then please enter the folder which image is in: ' folder
        if [ ! -d $folder ]
        then
            echo "There is no such a folder. Try again."
            echo "Do not forget to write the full path!"
            echo
            ((++alert))
        else
            echo "Okay."
            alert=5
        fi
    done
    if [ $alert -eq 5 ]
    then
        echo "Waiting for the program response, please be patient."
        count=0
        while [ $count -lt 10 ]
        do
            printf '. '
            sleep 1s
            ((++count))
        done
        echo "verified"
    else
        echo "Input buffer filled. Exiting the program!"
    fi
else
    echo "Waiting for the program response, please be patient."
    count=0
    while [ $count -lt 10 ]
    do
        printf '. '
        sleep 1s
        ((++count))
    done
    echo "no"
fi
