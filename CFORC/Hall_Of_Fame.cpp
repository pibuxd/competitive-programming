#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int solve(){
  int n; cin >> n;
  bool l = false, r = false;
  char b = ' ';
  int ret = -1;
  for(int i = 1; i <= n; i++){
    char a; cin >> a;
    if(ret != -1) continue;
    if(a == 'L'){
      l = true;
      if(r)
        ret = 0;
    }
    if(a == 'R'){
      r = true;
      if(b == 'L')
        ret = i-1;
    }
    b = a;
  }
  return ret;
}

int main(){
  fastio;
  int t; cin >> t;
  while(t--)
    cout << solve() << "\n";
}
