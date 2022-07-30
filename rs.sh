#!/bin/sh

if [[ ! -f sol.cpp ]]
then
    echo "no solution file"
else
    g++ -o sol sol.cpp
    ./sol
fi
