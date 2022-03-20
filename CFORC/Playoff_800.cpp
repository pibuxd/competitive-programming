#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int solve(int n){
  // if(n == 1) return 1;
  return (1<<n) - 1;
}

signed main(){
  fastio;
  int t; cin >> t;

  while(t--){
    int n; cin >> n;
    cout << solve(n) << "\n";
  }
}