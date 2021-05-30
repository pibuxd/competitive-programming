// Generator that randomizes numbers on an interval
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// @return random number in the range of (a, b)
int random_number(int a, int b){
  return a + rand()%(b - a + 1);
}

string random_string(int n){
  size_t s_len = 26;
  char letters[s_len] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
  'r','s','t','u','v','w','x',
  'y','z'};

  string ran = "";
  for(int i = 0; i < n; i++) 
    ran += letters[rand() % s_len];

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

  int n = 3;
  cout << n << "\n";
  string s;

  s = random_string(15);
  s += s + s;
  cout << s << "\n";

  s = random_string(20);
  s += s + s;
  cout << s << "\n";

  s = random_string(10);
  s += random_string(11) + s + s;
  cout << s << "\n";
}