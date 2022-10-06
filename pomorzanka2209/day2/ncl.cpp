#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, t, logn;
vector<vector<int>> G, up;
vector<int> d;

void dfs(int v, int p){
  d[v] = d[p] + 1;
  up[v][0] = p;
  for(int i = 1; i <= logn; i++)
    up[v][i] = up[up[v][i-1]][i-1];

  for(int x : G[v]){
    if(x == p) continue;
    dfs(x, v);
  }
}

int lca(int a, int b){
  if(d[a] < d[b]) swap(a, b);
  int k = d[a] - d[b];

  for(int i = 0; i <= logn; i++)
    if(k & (1 << i))
      a = up[a][i];

  if(a == b) return a;

  for(int i = logn; i >= 0; i--)
    if(up[a][i] != up[b][i])
      a = up[a][i], b = up[b][i];

  return up[a][0];
}

int jump(int a, int k){
  for(int i = 0; i <= logn; i++)
    if(k & (1 << i))
      a = up[a][i];
  return a;
}

int solve(int a, int b){
  int lc = lca(a, b);
  if((d[a] + d[b] - 2*d[lc]) % 2 == 1) return -1;
  
  if(d[a] < d[b]) swap(a, b);

  return jump(a, (d[a]+d[b]-2*d[lc])/2);
}

int main(){
  fastio;
  cin >> n >> t;
  logn = ceil(log2(n))+1;
  G.resize(n+1);
  up.resize(n+1, vector<int>(logn+1));
  d.resize(n+1);

  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  dfs(1, 0);

  while(t--){
    int a, b; cin >> a >> b;
    int s = solve(a, b);
    if(s != -1) cout << s;
    else cout << "NIE";
    cout << "\n";
  }
}
