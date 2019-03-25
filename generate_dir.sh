#!/bin/sh

input_files=$1

> tmp

awk -F'\t' '{
    name="";
    num=$1;
    name_ori=$2;
    n = split(name_ori, arr, " ");
    for (i = 1; i <= n; ++i)
    {
	if (arr[i] == "") continue;
	if (name == "") name = arr[i];
	else name = name"_"arr[i];
    }
    difficulty=substr($5,1,1);
    print num"."name"("difficulty")";
}' $input_files > tmp

cat tmp | while read line
do
    if [[ ! -d $line ]]
    then
        mkdir $line
    fi
done

rm -f tmp
