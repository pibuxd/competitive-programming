#!/bin/bash
# portable tester for competetive programming (CP)

name=$1
tests_dir=$2
prefix=${3:-}

g++ -O3 -Wall -Wextra -o $name $name.cpp
printf "compiled\nfile=${name}.cpp, testing directory=${tests_dir}, prefix=${prefix}\n"

for ((i = 0; i <= 100000; i++)); do
  nameout="${tests_dir}/out/${prefix}${i}.out"
  namein="${tests_dir}/in/${prefix}${i}.in"

  if [ ! -f $nameout ]; then
    continue
  fi

  ./$name < $namein > temp.out

  if diff -b temp.out $nameout > /dev/null; then
    printf "test: $i OK \r"
  else
    printf "test: $i ERROR"
    break
  fi

done

printf "\n"

rm -f $name temp.out