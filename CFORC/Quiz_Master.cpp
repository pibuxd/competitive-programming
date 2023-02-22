#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, mxn = 1e5, INF = 1e6;
vector<int> a;
vector<vector<int>> V;

int solve(){
  cin >> n >> m;
  a.assign(n+1, 0);
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());

  int l = 0, r = 0, sum = m;
  vector<int> vis(m+1, 0);
  int ans = INF;

  while(r < n){
    r++;
    for(int f : V[a[r]]){
      if(f > m) break;
      if(!vis[f]) sum--;
      vis[f]++;
    }
    while(l <= r && !sum){
      for(int f : V[a[l]]){
        if(f > m) break;
        vis[f]--;
        if(!vis[f]) sum++;
      }
      ans = min(ans, a[r]-a[l]);
      l++;
    }
  }

  if(ans == INF)
    return -1;
  return ans;
}

int main(){
  fastio;
  V.resize(mxn+1);
  for(int i = 1; i <= mxn; i++)
    for(int j = i; j <= mxn; j += i)
      V[j].push_back(i);

  int t; cin >> t;
  while(t--) cout << solve() << "\n";
}
