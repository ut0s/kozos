#!/bin/bash
# @date Time-stamp: <2020-05-08 11:01:15 tagashira>
# @file connect.sh
# @brief

# cu command doesn't work properly
# cu -l --parity=none --nostop --speed 9600 /dev/ttyUSB0
# cu -l --parity=none --nostop --speed 9600 /dev/ttyUSB1
minicom
