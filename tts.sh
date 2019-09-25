#!/bin/bash
#sed -n -e $1",300p" "$2" > /tmp/output_temp.txt;
sum1=$(($1+$2))
echo $sum1
sed -n -e $1","$sum1"p" "$3" > /tmp/output_temp.txt;
#echo "$(cat /tmp/output_temp.txt)"
pico2wave -w=/tmp/test.wav "$(cat /tmp/output_temp.txt)"
aplay /tmp/test.wav
rm /tmp/test.wav

