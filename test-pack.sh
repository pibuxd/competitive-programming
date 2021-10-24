#!/bin/bash
# portable tester for competetive programming (CP)
# test package of tests for program $1

g++ -O3 -Wall -Wextra -o $1 $1.cpp
printf "compiled\n"

for ((i = 25; i <= 999; i++)); do
  nameout="out/$1${i}.out"
  namein="in/$1${i}.in"

  if [ ! -f $nameout ]; then
    continue
  fi

  ./$1 < $namein > a.out

  if diff -b a.out $nameout > /dev/null; then
    printf "test: $i OK \r"
  else
    printf "test: $i ERROR"
    break
  fi

done

printf "\n"

rm -f $1 a.out