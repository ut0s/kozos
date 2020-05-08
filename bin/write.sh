#!/bin/bash
# @date Time-stamp: <2020-05-07 23:48:46 tagashira>
# @file write_OS.sh
# @brief

cd `dirname $0`
cd ..
BASE=$(pwd)
echo $BASE
sudo ./bin/h8write -3069 -f20 kzload.mot /dev/ttyUSB0
# sudo ./bin/h8write -3069 -f20 kzload.mot /dev/ttyUSB1
