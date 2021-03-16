// Generator that randomizes numbers on an interval
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
  fastio;

  init_Seed();

  int t, n, m, q, p, k, l;

  t = 1;
  n = random_number(2, 10);
  q = 5;

  cout << n << ' ' << q << '\n';

  while(q--){
    p = random_number(1, n);
    k = random_number(0, n-p);

    cout << k << ' ' << p << '\n';
  }
  

}