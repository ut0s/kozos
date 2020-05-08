#!/bin/bash
# @date Time-stamp: <2020-05-08 10:25:37 tagashira>
# @file build_env.sh
# @brief

cd `dirname $0`
cd ..
BASE=$(pwd)
echo $BASE

docker build . -t h8300:ubuntu
# test enviroment
docker run -it --rm --name kozos -v $BASE:/home/kozos -w /home/kozos h8300:ubuntu h8300-elf-gcc -v

# Download h8write
cd $BASE/bin
file=h8write
if [ -e $file ]; then
    echo "$file found."
    chmod u+x $file
else
    echo "$file NOT found."
    wget http://mes.osdn.jp/h8/h8write
    chmod u+x $file
fi
