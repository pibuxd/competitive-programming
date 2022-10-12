#!/bin/bash

n=$1
g++ -o gen -O3 gen.cpp
printf "compiled\n"

for ((i = 1; i <= $n; i++)); do
  echo $i > zi
  ./gen < zi > inp${i}
  printf "$i \r"
done

printf "done\n"
rm -f zi
