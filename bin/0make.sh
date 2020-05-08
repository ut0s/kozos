#!/bin/bash
# @date Time-stamp: <2020-05-08 10:24:23 tagashira>
# @file 0make.sh
# @brief

cd `dirname $0`
cd ..
BASE=$(pwd)
echo $BASE

docker run -it --rm --name kozos\
       -u user\
       -v $BASE:/home/kozos\
       -w /home/kozos\
       h8300:ubuntu make $@

# reference
# docker run -it --rm --name kozos\
#        -u user\
#        -v $BASE/ref/osbook_03/01/bootload:/home/kozos\
#        -w /home/kozos h8300:ubuntu make $@
