#!/bin/bash

Current_Dir="$(pwd)"
sed -i "s|~/Desktop/Panorama|${Current_Dir}|g" makefile

