#!/bin/bash
# portable tester for competetive programming (CP)

g++ -O3 -Wall -Wextra -o generator generator.cpp
g++ -O3 -Wall -Wextra -o brute brute.cpp
g++ -O3 -Wall -Wextra -o pattern pattern.cpp
printf "compiled\n"

for ((i = $1; i <= $2; i++)); do
  echo $i > ziarno
  ./generator < ziarno > input.in
  ./brute < input.in > brute.out
  ./pattern < input.in > pattern.out

  if diff -b brute.out pattern.out > /dev/null; then
    printf "test: $i OK \r"
  else
    printf "test: $i ERROR"
    break
  fi

done

printf "\n"

rm -f ziarno input.in pattern.out brute.out brute pattern generator