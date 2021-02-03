#include "bits/stdc++.h"
using namespace std;

int sumDig(int a){
  int sum = 0;

  while(a > 0){
    sum += a % 10;
    a /= 10;
  }

  return sum;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a, b;
  cin >> a >> b;

  int ans = 0;

  while(a <= b){
    if(a % 7 == 0 || sumDig(a) % 7 == 0)
      ans++;
    a++;
  }

  cout << ans;
}
