#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, k, ans;
vector<int> subh;
vector<vector<int>> G;

void dfs(int v, int p){
  vector<int> ch;

  for(int x : G[v]){
    if(x == p) continue;
    dfs(x, v);
    ch.push_back(subh[x]);
    
  }
  sort(all(ch));
  
  for(auto s : ch){
    if(subh[v] + s <= k)
      subh[v] += s;
    else
      ans++;
  }
}

int main(){
  fastio;
  cin >> n >> k;
  subh.resize(n+1);
  G.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> subh[i];
  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  ans = 0;
  dfs(1, 0);
  
  cout << ans << "\n";
}
