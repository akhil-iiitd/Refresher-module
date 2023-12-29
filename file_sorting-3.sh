#!/bin/bash
echo "enter the full path of the directory name"
read directory_name

if [ -d "$directory_name" ];
then
	sorted_f=$(ls $directory_name | sort)
	mkdir -p sorted
	count=0
	for i in $sorted_f;
	do
		mv $directory_name/$i sorted
		count=$(( count+1 ))
	done
	echo "Success !!!"
	echo "Moved $count files"
		
else
	echo "$directory not found"
fi
	


