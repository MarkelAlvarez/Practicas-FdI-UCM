#!/bin/bash

MPOINT="./mount-point"

rm -R -f test
mkdir test

echo 'file 1' > ./test/file1.txt
echo "Copying file 1"
cp ./test/file1.txt $MPOINT/
read -p "Press enter..."

echo "Creating file 2"
echo 'This is file 2' > $MPOINT/file2.txt
ls $MPOINT -la
read -p "Press enter..."

