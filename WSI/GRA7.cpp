#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n;

string solve(){
  cin >> n;

  int x = n, l = 0;
  while(x % 2 == 0){
    l++;
    x /= 2;
  }
  if(l % 2 == 0) 
    return "TAK";
  return "NIE";
}

signed main(){
  fastio;
  int q; cin >> q;
  while(q--) cout << solve() << "\n";
}
