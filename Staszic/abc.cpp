// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, ans, MOD = 1e9+7;
string s;

void foo(int it, int last, string curr){
  if(it == 7)
  if(curr[0] != curr[1] && curr[0] != curr[2] && curr[0] != curr[3]
  && curr[1] != curr[2] && curr[1] != curr[3] && curr[2] != curr[3]){
    ans++;
  }

  for(int i = last+1; i <= (n-1)-(6-it); i++){
    if(it <= 4){
      foo(it+1, i, curr+s[i]);
    }
    else if(it == 5){
      if(curr[2] == s[i])
        foo(it+1, i, curr+s[i]);
    }
    else if(it == 6){
      if(curr[3] == s[i])
        foo(it+1, i, curr+s[i]);
    }
  }
}

int main(){
  fastio;
  cin >> s;
  n = s.size();
  ans = 0;
  foo(1, -1, "");

  cout << ans % MOD;
}