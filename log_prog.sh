log_dir="./logs"								#initialising the log directory

logs=$(ls "$log_dir")							#listing all files in log_dir

date_num=$(echo "$(date +%F)")					#saving current date
cur_date=$(echo "${date_num:8:10}")				#Extracting the date day value from the whole date


for log in $logs;								#looping through all dates
do
	count=0
	log_array=()
	for word in $(cat "$log_dir/$log");			#Looking at each word form the log
	do

		if [ $count == 1 ]
		then
			echo ${word:8:10}>bing_text			
			consider_word=${word:8:10}			#Taking only the date day value from the log

			if [ $cur_date -gt $consider_word ]
			then
				echo "Filtering file.."			#Filtering out all the dates which falls below the current date day
				rm "$log_dir/$log"	
			fi		
		fi

		if [ $count -eq 3 ]
		then
			log_array+=$(echo -e " \n ")
		fi
		log_array+=$(echo "$word ")
		count=$((count+1))
			

	done
	echo "$log_array   "
	echo -e " \n "

	
done
	cur_date=$(date)
	#date_val=$(date -f <(echo "$cur_date") "+%Y-%m-%d %H:%M:%S")
	#echo "Current date : $cur_date"
	  	
