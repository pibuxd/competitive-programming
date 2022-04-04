// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef unsigned long long ull;

ull n;

bool prime(ull x){
  if(x == 0 || x == 1){
    return false;
  } else{
    for(int i = 2; i <= x/2; i++){
      if(x % i == 0){
        return false;
      }
    }
  }

  return true;
}

int main(){
  fastio;
  ull t;
  cin >> t;

  while(t--){
    cin >> n;
    ull maximum = 0;
    ull ziemniak = 1;

    for(ull i = 2; i <= n; i++){
      ull sum = 0;

      for(ull j = 2; j <= i/2; j++){
        if(prime(i/j) && i % j == 0){
          sum += j;
        }
      }

      if(prime(i)){
        sum += i;
      }

      if(sum >= maximum){
        maximum = sum;
        ziemniak = i;
      }
    }

    cout << ziemniak << '\n';
  }
}