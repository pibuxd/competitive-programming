// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, ans;
vector<int> x;

int main(){
  fastio;
  cin >> n;
  x.resize(n+1);
  
  for(int i = 1; i <= n; i++)
    cin >> x[i];

  ans = 0;

  bool is_zero = false;
  while(!is_zero){
    is_zero = true;

    for(int i = 1; i <= n; i++){
      if(x[i] == 0) continue;

      is_zero = false;
      if(x[i] % 2 != 0)
        x[i]--, ans++;
    }

    bool __is_zero = true;
    for(int i = 1; i <= n; i++){
      if(x[i] != 0)
        __is_zero = false;
      x[i] /= 2;
    }
    if(!__is_zero)
      ans++;
  }

  cout << ans;
}