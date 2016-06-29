if [[ -f testdata ]]; then
    #statements
    rm testdata
fi

for (( i = 0; i < 10000; i++ )); do
    echo $RANDOM >> testdata
done  


