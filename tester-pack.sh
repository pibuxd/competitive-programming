#!/bin/bash
# portable tester for competetive programming (CP)

name=$1
tests_dir=$2

g++ -O3 -Wall -Wextra -o $name $name.cpp
printf "compiled\n"

for ((i = 25; i <= 999; i++)); do
  nameout="${tests_dir}/out/${name}${i}.out"
  namein="${tests_dir}/in/${name}${i}.in"

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