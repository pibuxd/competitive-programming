#!/bin/bash
# author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
# portable tester for competetive programming (CP)

g++ -O3 -o generator generator.cpp
g++ -O3 -o brute brute.cpp
g++ -O3 -o pattern pattern.cpp
printf "compiled\n"

for ((i = $1; i <= $2; i++)); do
  echo $i > ziarno.temp
  ./generator < ziarno.temp > input.in
  ./brute < input.in > brute.out
  ./pattern < input.in > pattern.out

  if diff -b brute.out pattern.out > /dev/null; then
    printf "test: $i OK \r"
  else
    printf "test: $i ERROR"
    # break
  fi

done

printf "\n"

rm -f ziarno.temp input.in pattern.out brute.out brute pattern generator