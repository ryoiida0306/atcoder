#!/bin/sh

. ./config.sh

filename=$1
output_file_name="./"$contest_name"/exefile"
input_file_name="./"$contest_name"/"$filename".cpp"

g++ $input_file_name -I./ac-library -o $output_file_name -std=c++17

if [ "$ahc" = "True" ]; then
    ./$output_file_name < "./$contest_name/input.txt" > "./$contest_name/output.txt" 2> "./$contest_name/error.txt"
    if [ "$ahc_in" = "True" ]; then
        mkdir -p ./$contest_name/out
        for i in `seq 0 99`; do
            num=$(printf "%04d" $i)
            ./$output_file_name < "./$contest_name/in/"$num".txt" > "./$contest_name/out/"$num"_"$filename"_"$num".txt" 2> "./$contest_name/error.txt"
        done
    fi
    exit 0
fi

echo "Compile done"
echo "---"
./$output_file_name > "./"$contest_name"/output.txt" 2> "./"$contest_name"/error.txt"

echo "標準出力"
echo "---"
cat "./"$contest_name"/output.txt"
echo "---"
echo ""
echo "エラー出力"
echo "---"
cat "./"$contest_name"/error.txt"
echo "---"

rm "./"$contest_name"/output.txt"
rm "./"$contest_name"/error.txt"
rm $output_file_name
