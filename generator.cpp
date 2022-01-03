// Generator that randomizes numbers on an interval
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// @return random int in the range of (a, b)
int ran_int(int a, int b){
  return a + rand()%(b - a + 1);
}

// @return random string
string ran_str(int n, int len){
  string ran = "";
  for(int i = 0; i < n; i++) 
    ran += (int)'a' + (rand() % len);

  return ran;
}

void init_Seed(){
  int seed;
  cin >> seed;
  srand(seed);
}

int main(){
  fastio;
  init_Seed();

  int x = ran_int(5, 10);
  string s = ran_str(6, 3);
  
  cout << x << "\n" << s;
}