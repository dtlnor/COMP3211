#!/bin/bash

gen_gcov() {

  gcc bugAlgo.c -fprofile-arcs -ftest-coverage -o bugAlgo
  

  ./bugAlgo $1 $2 $3 $4 $5 > bugAlgoFile.csv
  bugVar=$(cat bugAlgoFile.csv)
  gcc trueAlgo.c -o trueAlgo
  ./trueAlgo $1 $2 $3 $4 $5 > trueAlgoFile.csv
  trueVar=$(cat trueAlgoFile.csv)
  
  gcov bugAlgo.c
  
  gcc gen_coverage.c -o gen_coverage
  ./gen_coverage "${bugVar[@]}" "${trueVar[@]}"
  
  #nano bugAlgo.c.gcov
  
}

#main
rm -rf testcase.csv bugAlgoResult.csv trueAlgoResult.csv coverageResult.csv TarantulaResult.csv CrossTabResult.csv

#gen testcase
gcc gen_testCase.c -o gen_testCase
./gen_testCase

input="./testcase.csv"
while IFS= read -r var
do
  IFS=',' # , is set as delimiter
  read -ra ADDR <<< "$var" # var is read into an array as tokens separated by IFS
  
  gen_gcov "${ADDR[0]}" "${ADDR[1]}" "${ADDR[2]}" "${ADDR[3]}" "${ADDR[4]}"

done < "$input"

rm -rf bugAlgo trueAlgo gen_testCase bugAlgo.gcda bugAlgo.gcno trueAlgoFile.csv bugAlgoFile.csv gen_coverage #bugAlgo.c.gcov

bash runDebug.sh

echo end