# Yaroslav Kolesnik
#!/bin/bash

while read -r line
do
    if [[ "$line" == "total"* ]]; then
        continue
    fi
    
    if [[ ${#line} -lt 10 ]]; then
        continue
    fi
    
    type=$(echo "$line" | cut -c1)
    permissions=$(echo "$line" | cut -c2-10)
    
    fields=($line)

    filename_pos=0
    for ((i=5; i<${#fields[@]}; i++)); do
        if [[ ${fields[i]} =~ [0-9][0-9]:[0-9][0-9] ]] || [[ ${fields[i]} =~ [0-9][0-9]:[0-9][0-9]:[0-9][0-9] ]]; then
            filename_pos=$((i+1))
            break
        fi
    done
    
    name=""
    for ((i=filename_pos; i<${#fields[@]}; i++)); do
        name+="${fields[i]} "
    done
    name=${name% }
    
    owner_perm=${permissions:0:3}
    group_perm=${permissions:3:3}
    others_perm=${permissions:6:3}
    
    owner_num=0
    if [[ $owner_perm == *"r"* ]]; then owner_num=$((owner_num + 4)); fi
    if [[ $owner_perm == *"w"* ]]; then owner_num=$((owner_num + 2)); fi
    if [[ $owner_perm == *"x"* ]]; then owner_num=$((owner_num + 1)); fi
    
    group_num=0
    if [[ $group_perm == *"r"* ]]; then group_num=$((group_num + 4)); fi
    if [[ $group_perm == *"w"* ]]; then group_num=$((group_num + 2)); fi
    if [[ $group_perm == *"x"* ]]; then group_num=$((group_num + 1)); fi
    
    others_num=0
    if [[ $others_perm == *"r"* ]]; then others_num=$((others_num + 4)); fi
    if [[ $others_perm == *"w"* ]]; then others_num=$((others_num + 2)); fi
    if [[ $others_perm == *"x"* ]]; then others_num=$((others_num + 1)); fi
    
    if [[ $type == "d" ]]; then
        echo "$name/ $owner_num$group_num$others_num"
    elif [[ $type == "-" && $owner_perm == *"x"* ]]; then
        echo "$name* $owner_num$group_num$others_num"
    else
        echo "$name $owner_num$group_num$others_num"
    fi
done