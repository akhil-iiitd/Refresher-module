#!/bin/sh

for(( i=0;i<8;i++))				#outer for loop
do
	for((j=0;j<8;j++))			#inner for loop
	do
		val=$(((i+j)%2))		#calculating the sum of i and j
		if [ $val -eq 0 ]		#checking if the value val is even
		then	
			echo -e -n "\u2588"	#If even , printing white
		else
			echo -e -n " "		#else, printing black	
		fi
	done
	echo " "
done
