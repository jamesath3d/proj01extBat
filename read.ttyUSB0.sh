#!/bin/bash
input="/dev/ttyUSB0"
######################################
# $IFS removed to allow the trimming #
#####################################
while read -r line
do
  echo "`date +%Y_%m%d_%H%M%P_%S______%s ` $line"
done < "$input"
