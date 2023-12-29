#!/bin/bash
echo "enter the full path of the directory name"			#prompting user to enter full path
read directory_name

#reading directory name

if [ -d "$directory_name" ];
#checking if directory name exists

then
	sorted_f=$(ls $directory_name | sort)					#sorting the files in the directory
	mkdir -p sorted											#making a directory named sorted
	count=0
	echo "The files in the directory are : "
	echo "$(ls -l $directory_name)"							#listing all files in the directory
	for i in $sorted_f;										#looping through all files in the directory
	do
		mv $directory_name/$i sorted						#moving all files to sorted directory
		count=$(( count+1 ))								#increment count
	done

	if [ $count -eq 0 ]										#checking if directory is empty
	then
		echo "No files in the directory to move"
	else
		echo "Success !!!"										#printing success message
	fi
	echo "Moved $count files"
		
else
	echo "$directory not found"								#printing directory not found message
fi
	


