# Yaroslav Kolesnik

read first_line
letter=${first_line:0:1}
case_sensitive=1
if [ -z "$first_line" ]; then
    exit 1
fi
if [[ $first_line == *"+"* ]]; then
    case_sensitive=0
fi

while read line
do
    if [[ "$case_sensitive" -eq 1 ]]; then
        count=$(echo "$line" | grep -o "$letter" | wc -l)
    else
        lower_letter=$(echo "$letter" | tr '[:upper:]' '[:lower:]')
        upper_letter=$(echo "$letter" | tr '[:lower:]' '[:upper:]')
        count1=$(echo "$line" | grep -o -F "$letter" | wc -l)
        count2=$(echo "$line" | grep -o -F "$upper_letter" | wc -l)
        count=$((count1 + count2))
    fi
    
    echo $count
done


