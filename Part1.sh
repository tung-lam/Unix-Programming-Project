#!/bin/bash

cont=true	
path="Image_path.txt"
txtrst=$(tput sgr0) # Text reset
txtred=$(tput setaf 1) # Red

### START FUNCTIONS
get_created_time() {
   for file in "${@}"; do
       inode=$(stat -c %i "${file}") 							### dis play file status to get inode
       filesystem=$(df "${file}"  | tail -1 | awk '{print $1}') ### output the $1 of the last line from the report file system disk space usage
       createdtime=$(sudo debugfs -R 'stat <'"${inode}"'>' "${filesystem}" 2>/dev/null | grep -oP 'crtime.*--\s*\K.*')
       															### request the file system debugger to get createdtime of the inode through the filesystem
   done
       printf "%s %s\n" "${file}" "${createdtime}"				
}

list_image(){

	echo "Which file do you want to print the results? Enter the filename."
	read listfile
	
	cat "$directory/$*" | while read eachfile				### read from each line in the Image_path.txt and use identify to list the detail of each image
	do
		# basename $eachfile
		filename=$(basename "$eachfile")
		filetype=$(identify "$eachfile" | awk -F" " '{print "\t" $2}')
		filesize=$(identify "$eachfile" | awk -F" " '{print "\t" $7}')
		filecreatedtime=$(get_created_time "$eachfile" | awk -F" " '{print "\t" $2" "$3" "$4" "$5" "$6}')

		# echo "Filename: $filename"
		# echo "Directory: $eachfile"
		# echo "Type: $filetype"
		# echo "Size: $filesize"
		# echo "Created time: $filecreatedtime"
		# echo " "
 
		echo "$filename |$eachfile |$filetype |$filesize |$filecreatedtime"
		echo " "

	done > "$listfile"

	echo " "
	echo "All image information is saved in file $listfile in directory $directory with the order:"
	echo "Filename | Directory | Type | Size | Created time" 
	echo " "
	cat $listfile
	
}
### FINISH PART 1.1

	
sort_image(){
	echo "Which feature do you want to sort? Enter a number."
	echo "1. Sort by name"
	echo "2. Sort by size"
	echo "3. Sort by created time"
	read choice

	case "$choice" in 
		1 )
			sort_name_path="Sort_by_name_path.txt"
			find "$directory" -type f -exec file {} \; -print | awk -F: '{ if ($2 ~/image/) print $1 }' |sort > "$sort_name_path"
	  		list_image "$sort_name_path"
	  		;;
	  	2 )
			sort_size_path="Sort_by_size_path.txt"
			find "$directory" -type f -exec file {} \; -print | awk -F: '{ if ($2 ~/image/) print $1 }'  | xargs du -h | sort -h  > Short-size.txt
	  																			### xarg: from standard input, du: estimate file space usage, -h:human readable
			cat "$directory/Short-size.txt" | while read eachfile				
			do
				onlypath=$(echo "$eachfile" | awk -F" " '{print "\t" $2}')
				echo $onlypath
			done > $sort_size_path
	  		list_image "$sort_size_path"
	  		;;
	  	3 )
			sort_created_path="Sort_by_created_date_path.txt"
			cat "$directory/$*" | while read eachfile				
			do
		 		echo "$(get_created_time "$eachfile")" 
			done > created_date_path.txt
 			echo "-------------------------------"
			sort -k3 -k4 created_date_path.txt > Short-created.txt		### -k:sort via a key
			cat "$directory/Short-created.txt" | while read eachfile				
			do
				onlypath=$(echo "$eachfile" | awk -F" " '{print "\t" $1}')
				echo $onlypath
			done > $sort_created_path
			list_image "$sort_created_path"
	  		;;
	  	* )
			echo "Invalid choice!"
			# break
			;;
		esac
}
### FINISH PART 1.2


files_same_name(){

find "$directory" -type f -exec file {} \; -print | awk -F: '{ if ($2 ~/image/) print $1 }' > $path
> same_name.txt
cat "$directory/$path" | while read eachfile	
do
    filename="$( basename "$eachfile" )"
    compared_name="$( grep "$filename" $path | grep -v "$eachfile" )"
    if [ "$compared_name" != "" ]
    	then
    	if !(grep -q "^${eachfile}" same_name.txt ); then
            echo -e "$eachfile"
            echo -e "$compared_name"
            echo " "
        fi
    fi
done > same_name.txt
# cat same_name.txt
}

highlight(){

	echo “This is ${txtred} high light text ${txtrst}!” 
}

search_image_by_keyword(){

	# list_image "$path"
	cat "$directory/$path" | while read eachfile				### read from each line in the Image_path.txt and use identify to list the detail of each image
	do
		filename=$(basename "$eachfile")
		filetype=$(identify "$eachfile" | awk -F" " '{print "\t" $2}')
		filesize=$(identify "$eachfile" | awk -F" " '{print "\t" $7}')
		filecreatedtime=$(get_created_time "$eachfile" | awk -F" " '{print "\t" $2" "$3" "$4" "$5" "$6}')
 
		echo "$filename |$eachfile |$filetype |$filesize |$filecreatedtime"
		echo " "

	done > "All_image.txt"

	echo " "
	echo "Enter a keyword: "
	read keyword
	
	echo "Which file do you want to print the results? Enter the filename."
	read result

	grep -A 0 -i "$keyword" All_image.txt > $result
	cat $result
}
### FINISH PART 1.5

### END FUNCITONS


### MAIN
echo "Enter the name of the directory you want to work with:"
read directory									###/home/linhtynny/Documents/Project/Unix-Programming-Project/Test

while [ $cont ]; do
	if [ ! -d $directory ] ; 						###check if folder exists
		then 
			echo "Directory $directory not found!" 
		else										###list all the image's path to Image_path.txt
			cd $directory
			# ls
			# find . -type f -exec file {} \; | grep -o -P '^.+: \w+ image' > Image_path.txt	##the image's path is not full
			find "$directory" -type f -exec file {} \; -print | awk -F: '{ if ($2 ~/image/) print $1 }' > $path
													###find the file (type) with the format:image in directory  and print the path to the file path
	fi

	# list_image "$path"
	# sort_image "$path"
	# files_same_name
	# search_image_by_keyword
	

	echo "What do you want to do? Choose an option:"
	echo "1. List all the images files with details"
	echo "2. Sort the files by different features"
	echo "5. Search image files by keyword"
	read option
	case "$option" in 
		1 ) list_image "$path" ;;
		2 ) sort_image "$path" ;;
		5 ) search_image_by_keyword ;;
		* ) echo "Invalid option! " ;;
	esac

	
	echo " "
	echo "Do you want to continue? Enter yes or no."
	read answer

	case "$answer" in
		yes | y | Yes | YES ) : ;;
		n* | N* | *)
			echo " **** Exit! ****"	
			exit 
			;;
	esac
done
exit 0

