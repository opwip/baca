# Yaroslav Kolesnik

read N

i=1
temp=0
temp2=1
while [ $i -le $N ] 
do
    echo $temp
    temp3=$(( $temp ))
    temp=$(( $temp + $temp2 ))
    temp2=$(( $temp3 ))
    i=$((i+1))
done