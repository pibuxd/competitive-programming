// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int A, B;

int romb(int x){
  int ans = x;
  int _x = x;

  while(_x > 0){
    ans *= _x%10;
    _x /= 10;
  }

  return ans;
}

signed main(){
  fastio;
  cin >> A >> B;

  int res = 0;

  for(int i = 1; i <= B; i++){
    int r = romb(i);
    if(A <= r && r <= B)
      res++;
  }

  cout << res;
}