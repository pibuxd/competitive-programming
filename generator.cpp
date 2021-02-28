// Generator that randomizes numbers on an interval
#include <bits/stdc++.h>
using namespace std;

// @return random number in the range of (a, b)
int random_number(int a, int b){
  return a + rand()%(b - a + 1);
}

void init_Seed(){
  int seed;

  cin >> seed;
  srand(seed);
}

int main(){
  init_Seed();


}