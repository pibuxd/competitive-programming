#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<int> solve(){
  int n; cin >> n;
  if(n == 1) return {1};
  if(n == 3) return {};
  if(n % 2 == 1){
    int t = n/2;
    int a = t-1, b = -t;
    vector<int> res;
    for(int i = 1; i <= n; i++)
      res.push_back((i % 2 == 0 ? b : a));
    return res;
  }
  vector<int> res;
  for(int i = 1; i <= n; i++)
    res.push_back((i % 2 == 0 ? 1 : -1));
  return res;
}

int main(){
  fastio;
  int t; cin >> t;
  while(t--){
    vector<int> s = solve();
    if(s.empty()) cout << "NO\n";
    else{
      cout << "YES\n";
      for(int x : s) cout << x << " ";
      cout << "\n";
    }
  }
}
