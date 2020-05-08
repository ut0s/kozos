#!/bin/bash
# @date Time-stamp: <2020-05-08 10:35:31 tagashira>
# @file get_reference.sh
# @brief

cd `dirname $0`
cd ..
BASE=$(pwd)
echo $BASE

cd $BASE
mkdir -p ref

# ref
echo "Download source code"
cd $BASE
cd ./ref

file=osbook_03.zip
if [ -e $file ]; then
    echo "$file found."
else
    echo "$file NOT found."
    wget http://kozos.jp/kozos/osbook/$file
    unzip $file
fi
