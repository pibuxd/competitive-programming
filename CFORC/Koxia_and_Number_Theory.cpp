#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

string solve(){
  int n; cin >> n;
  vector<int> a(n+1);
  unordered_set<int> x;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  for(int i = 1; i <= n; i++){
    if(x.count(a[i])) return "NO";
    else x.insert(a[i]);
  }
  
  for(int p = 2; p <= n/2; p++){
    vector<int> c(p, 0);
    for(int i = 1; i <= n; i++)
      c[a[i] % p]++;
    int mn = 2;
    for(int i = 0; i <= p-1; i++)
      mn = min(mn, c[i]);
    if(mn == 2) return "NO";
  }
  return "YES";
}

signed main(){
  fastio;
  int t; cin >> t;
  while(t--) cout << solve() << "\n";
}
