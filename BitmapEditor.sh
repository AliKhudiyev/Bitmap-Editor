#!/bin/bash

echo "Welcome to the Bitmap Editor V1.0."

echo "Used programming languages : C, C++(17)"
echo "Current available version : 1.0."
echo "Written by : Ali Khudiyev"
echo "Simple terminal based image editor"
echo "Needed bash/shell version : Bash"
echo "27 user-frinedly commands"
echo "2 processing modes : S.T.P. and M.T.P."
echo "Various error handlings and brief information for each of them"
echo
echo "Note: If any bugs are found feel free to open up a new issue in my github"
echo "Note: For more detailed information about the program visit https://github.com/AliKhudiyev/Bitmap-Editor"
echo

sleep 5s

echo "Which mode do you want to enter? 0/1"
echo "0 - Single-Time Processing or S.T.P."
echo "1 - Multi-Time Processing or M.T.P."
read mode

if [ $mode == 0 ]
then
    echo "S.T.P. mode has been selected."
    ./STPmode.sh
elif [ $mode == 1 ]
then
    echo "M.T.P. mode has been selected."
    echo
    ./MTPmode.sh
else
    echo "No such an option. Quit code has been activated."
fi
