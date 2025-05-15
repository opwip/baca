# Yaroslav Kolesnik

sum=0
count=0
sum_squares=0

while read line
do
    if [[ $line =~ ^[0-9]+$ ]]; then
        sum=$((sum + line))
        sum_squares=$((sum_squares + line * line))
        count=$((count + 1))
    fi
done

if [ $count -gt 0 ]; then
    mean=$((sum / count))
    variance=$(((sum_squares - (sum * sum / count)) / count))
    echo $mean
    echo $variance
fi