#!/bin/bash

gen_gcov() {

  echo $1
  gcc bugAlgo.c -fprofile-arcs -ftest-coverage -o bugAlgo
  ./bugAlgo
  gcov bugAlgo.c
  #nano bugAlgo.c.gcov
  
}

for i in {1..2}
do
  gen_gcov "$i"
done

rm -rf bugAlgo bugAlgo.gcda bugAlgo.gcno

echo end