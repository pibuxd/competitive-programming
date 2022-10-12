#!/bin/bash

en=$1
g++ -o pat -O3 pat.cpp
#g++ -o gen -O3 gen.cpp
#g++ -o brut -O3 brut.cpp
#g++ -o check -O3 check.cpp
printf "compiled\n"
er=0

for ((i = 1; i <= $en; i++)); do
  #echo $i > zi
  #./gen < zi > inp
  ./pat < inp${i} > patout
  currk=$(./check < patout)
  k=$(./brut < inp${i})
  #echo $currk; continue
  d=$(echo "scale=3; ${currk}/${k}" | bc)
  # printf 'xd: %.3f\n' $d
  w=0.65

  if (( $(echo "$w <= $d" | bc) )); then
    printf "test: $i OK: %.3f\r" $d
  else
    printf "test: $i ERROR: %.3f\r" $d
    er=$(echo "${er}+1" | bc)
    #break
  fi

done

printf "\n${er}, %.4f\n" $(echo "scale=4; 1-${er}/${en}" | bc)

rm -f pat inp
#rm -f gen pat brut check inp
