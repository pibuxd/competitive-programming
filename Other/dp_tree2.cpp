#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, sum;
vector<vector<int>> G;
vector<bool> vis;

void dfs(int v, int p){
  for(int x : G[v]){
    if(x == p) continue;
    dfs(x, v);
    if(!vis[x] && !vis[v]) 
      vis[x] = vis[v] = true, sum++;
  }
}

int main(){
  fastio;
  cin >> n;
  G.resize(n+1);

  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  sum = 0;
  vis.assign(n+1, false);
  dfs(1, 0);
  cout << sum << "\n";
}


