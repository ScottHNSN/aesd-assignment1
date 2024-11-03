filedir="$1"
searchstr="$2"
if [ -z "$filedir" ] || [ -z "$searchstr" ]; then
	echo "Please specify both a directory and what to search for!"
	exit 1
elif [ -d "$filedir" ]; then 
		echo "The number of files are $(find "$filedir" -type f | wc -l) and the number of matching lines are $(grep -r "$searchstr" "$filedir" | wc -l)" 
		exit 0
	else
		echo "please pass an existing directory as argument!"
		exit 1
	fi
