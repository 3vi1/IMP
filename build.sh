#!/bin/bash
mkdir build
cd build
qmake --qt=5 ../src/imp.pro
make
sudo make install
