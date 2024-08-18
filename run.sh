#!/bin/sh

contest_name="test"
filename=$1
output_file_name="./"$contest_name"/exefile"
input_file_name="./"$contest_name"/"$filename".cpp"

g++ $input_file_name -I./ac-library -o $output_file_name
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