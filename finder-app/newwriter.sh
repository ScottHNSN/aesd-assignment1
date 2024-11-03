#!/bin/bash
writefile=$1
writestr=$2
if [ -z $writefile ] || [ -z $writestr ]
then
	exit 1
else
	echo $writestr > $writefile
	exit 0
fi
