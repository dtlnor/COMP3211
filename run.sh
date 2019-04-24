#!/bin/bash

gen_gcov() {

  gcc bugAlgo.c -fprofile-arcs -ftest-coverage -o bugAlgo
  ./bugAlgo $1 $2 $3 $4 $5
  gcov bugAlgo.c 
  #nano bugAlgo.c.gcov
  
}

#main

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

rm -rf bugAlgo gen_testCase bugAlgo.gcda bugAlgo.gcno 

echo end