#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, m, nrpre, nrpost, teammostnr, logn;
vector<vector<int>> G, up;
vector<int> pre, post, low, d;

int lca(int a, int b){
  if(d[a] < d[b]) swap(a, b);
  int k = d[a]-d[b];
  for(int i = 0; i <= logn; i++)
    if(k & (1<<i))
      a = up[a][i];
  if(a == b) return a;
  for(int i = logn; i >= 0; i--)
    if(up[a][i] != up[b][i])
      a = up[a][i], b = up[b][i];
  return up[a][0];
}

void dfs(int v){
  low[v] = pre[v] = ++nrpre;

  for(int x : G[v]){
    if(!pre[x]){
      d[x] = d[v]+1;
      up[x][0] = v;
      for(int i = 1; i <= logn; i++)
        up[x][i] = up[up[x][i-1]][i-1];
      dfs(x);

      low[v] = min(low[v], low[x]);
    } else{
      low[v] = min(low[v], pre[x]);
    }
  }

  post[v] = ++nrpost;
}

bool ispod(int v, int p){
  return (pre[v] >= pre[p] && post[v] <= post[p]);
}

int main(){
  fastio;
  cin >> n >> m;
  logn = ceil(log2(n));
  up.resize(n+1, vector<int>(logn+1));
  d.resize(n+1);
  G.resize(n+1); 

  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  nrpre = nrpost = 0;
  pre.resize(n+1); 
  post.resize(n+1); 
  low.resize(n+1); 
  for(int i = 1; i <= n; i++)
    if(!pre[i])
      dfs(i);
  
  int q; cin >> q;
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int a, b, x, y; cin >> a >> b >> x >> y;
      if(d[x] < d[y]) swap(x, y);
      
      if((ispod(a, y) || ispod(b, y)) && low[x] > pre[y])
        if((ispod(a, x) && !ispod(b, x)) || (!ispod(a, x) && ispod(b, x))){
          cout << "NIE\n";
          continue;
        }

      cout << "TAK\n";

    } else if(op == 2){
      int a, b, c; cin >> a >> b >> c;
      if(!ispod(a, c)) swap(a, b);
      
      if( true
      ) cout << "NIE\n";
      else cout << "TAK\n";
    }
  }
}
