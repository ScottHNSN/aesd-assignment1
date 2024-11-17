#!/bin/bash
writefile=$1
writestr=$2
if [ -z $writefile ] || [ -z $writestr ]
then
	exit 1
else
	if [ ! -d "$(dirname "$writefile")" ];
	then
		mkdir -p "$(dirname "$writefile")" || exit 2 
	fi
	echo "$writestr" > "$writefile"
	exit 0
fi
