#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define MX (int)(1e9)

void solve(int n){
  vector<int> ans;

  int curr = 1;
  ans.push_back(1);

  for(int i = 2; i <= n; i++){
    curr *= 3;
    if(curr > MX){
      cout << "NO\n";
      return;
    }

    ans.push_back(curr);
  }

  cout << "YES\n";
  for(int i : ans) cout << i << " ";
  cout << "\n";
}

signed main(){
  fastio;
  int t; cin >> t;

  while(t--){
    int n; cin >> n;
    solve(n);
  }
}