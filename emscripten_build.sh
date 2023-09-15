#!/bin/bash

# make sure we are in the project directory
cd /src

# delete the files in the build folder
# this is for when we run locially, on a fresh clone, build folder will not exist
rm -rf /src/build/*

# re-create the build folder (does nothing if already exists)
mkdir build

# Run CMake in build folder
# this will populate the build folder
cd ./build
emcmake cmake ..

# run make - this will compile our project
emmake make