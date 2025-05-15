# Yaroslav Kolesnik

declare -A counts
declare -A first_pos
line=0

while read id
do
    if [ -n "$id" ]; then
        line=$((line + 1))
        
        if [ -z "${counts[$id]}" ]; then
            counts[$id]=1
            first_pos[$id]=$line
        else
            counts[$id]=$((counts[$id] + 1))
        fi
    fi
done

min_count=999999
min_id=""

for id in "${!counts[@]}"
do
    if [ ${counts[$id]} -lt $min_count ]; then
        min_count=${counts[$id]}
        min_id=$id
    elif [ ${counts[$id]} -eq $min_count ]; then
        if [ ${first_pos[$id]} -lt ${first_pos[$min_id]} ]; then
            min_id=$id
        fi
    fi
done

echo "$min_id $min_count"