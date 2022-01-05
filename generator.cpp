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

// @return random vector with int in the range of (a, b)
vector<int> ran_vec(int n, int a, int b){
  vector<int> ran(n, 0);
  generate(ran.begin(), ran.end(), [a, b](){ return ran_int(a, b); });

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

  vector<int> v = ran_vec(3, 4, 9);
  int x = ran_int(5, 10);
  string s = ran_str(6, 3);

  for(int i : v)
    cout << i << " ";
  cout << "\n";

  cout << x << "\n"; 
  cout << s << "\n";
}