#!/bin/sh

for(( i=0;i<8;i++))
do
	for((j=0;j<8;j++))
	do
		val=$(((i+j)%2))
		if [ $val -eq 0 ]
		then	
			echo -e -n "\u2588"
		else
			echo -e -n " "
		fi
	done
	echo " "
done
