#!/bin/zsh
# tester for competetive programming (CP)

# color variables
green=$(tput setaf 72);
red=$(tput setaf 1);
blue=$(tput setaf 32);
orange=$(tput setaf 178);
magenta=$(tput setaf 5)
bold=$(tput bold);
reset=$(tput sgr0);

function help () {
  echo "usage:"
  echo -ne "\ttester [operation] <param> \n\n"
  echo "operations:"
  echo -ne "\ttest ==> run test cases genarated on seed from <param2> to ∞\n"
  echo -ne "\tgen ==> print generated input for seed <param2>\n"
  echo -ne "\n"
  echo "defaults:"
  echo -ne "\t<param1> ==> help\n"
  echo -ne "\t<param2> ==> 0"
  echo -ne "\n"; exit 1
}

arg1=$1
arg2=$2
arg3=$3

if [[ "$1" != "" ]]; then
  if [[ "$1" != "test" && "$1" != "gen" && "$1" != "help" ]]; then
    echo -ne "${red}bad operation:${reset} \"$1\"\n\n"
    help
    exit 1
  fi
fi

if [[ "$1" == "help" || "$1" == "" ]]; then
  help
  exit 1
fi

# compile generator with CP flags
START=$(date +%s.%N)
g++ -o generator generator.cpp ||
{ echo "generator.cpp -> ${bold}${red}compilation error${reset}"; exit 1; }
DIFF=$(echo "$(date +%s.%N) - $START" | bc)
printf "generator.cpp -> ${bold}${green}compiled${reset} in %.6f sec \n" $DIFF 

if [[ "$2" == "" ]]; then
    arg2=0
fi

if [[ "$3" == "" ]]; then
    arg3=arg2
fi

if [[ "$1" = "test" ]]; then
  # testing

  # compile brute and pattern with CP flags
  START=$(date +%s.%N)
  g++ -o brute brute.cpp ||
  { echo "brute.cpp -> ${bold}${red}compilation error${reset}"; exit 1; }
  DIFF=$(echo "$(date +%s.%N) - $START" | bc)
  printf "brute.cpp -> ${bold}${green}compiled${reset} in %.6f sec \n" $DIFF

  START=$(date +%s.%N)
  g++ -o pattern pattern.cpp || 
  { echo "pattern.cpp -> ${bold}${red}compilation error${reset}"; exit 1; }
  DIFF=$(echo "$(date +%s.%N) - $START" | bc)
  printf "pattern.cpp -> ${bold}${green}compiled${reset} in %.6f sec \n" $DIFF

  echo -ne "\n"

  MAX_TIME=0
  MAX_TEST=0

  printf "${bold}${blue}testing...${reset}\n"

  for ((i = $arg2; i <= $arg3; i++)); do
    echo $i > ziarno
    ./generator < ziarno > input.in
    ./brute < input.in > brute.out
    START=$(date +%s.%N)
    ./pattern < input.in > pattern.out
    END=$(date +%s.%N)
    DIFF=$(echo "$(date +%s.%N) - $START" | bc)

    if (( $( echo "$DIFF > $MAX_TIME" | bc) )); then
      MAX_TIME=$DIFF
      MAX_TEST=$i
    fi

    if diff -b brute.out pattern.out > /dev/null; then
      printf "test: $i${green} OK${reset} in %.6f sec \r" $DIFF
    else
    # if [ -n "$(diff -b brute.out pattern.out)" ]; then
      printf "test: $i${red} ERROR${reset} in %.6f sec" $DIFF
      break
    fi

  done
  printf "\nMax time on test: ${magenta}$MAX_TEST${reset} in %.6f sec \n" $MAX_TIME

elif [[ "$1" = "gen" ]]; then
  # print input of the input generator

  echo -ne "\ninput for test: ${magenta}${arg2}${reset}\n"
  echo $arg2 > ziarno
  ./generator < ziarno
  echo -ne "\n"
fi

# remove temporary files
rm -f ziarno input.in pattern.out brute.out brute pattern generator