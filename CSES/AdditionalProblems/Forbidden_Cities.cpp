#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
int n, m, q, nr, L, prid, pstid;
vector<vector<int>> G;
vector<int> low, pre, pres, posts, d;
vector<vector<int>> T, up;
 vector<int> st;
void ae(int a, int b){
  T[a].push_back(b);
  T[b].push_back(a);
}
 
void dfs(int v, int p){
  pre[v] = low[v] = ++nr;
  st.push_back(v);

  for(int x : G[v]){
    if(x == p) continue;
    if(!pre[x]){
      dfs(x, v);
      low[v] = min(low[v], low[x]);
      if(low[x] >= pre[v]){
        ae(v, n+low[x]);
        do{
        } while(T[n+low[v]].back() != x))
      }
 
    } else
      low[v] = min(low[v], pre[x]);
  }
}
 
void dfslc(int v, int p){
  pres[v] = ++prid;
  d[v] = d[p] + 1;
  up[v][0] = p;
 
  for(int i = 1; i <= L; i++)
    up[v][i] = up[up[v][i-1]][i-1];
 
  for(int x : T[v]){
    if(x == p) continue;
    dfslc(x, v);
  }
  posts[v] = ++pstid;
}
 
int lca(int a, int b){
  if(d[a] < d[b]) swap(a, b);
  int k = d[a] - d[b];
 
  for(int j = 0; j <= L; j++)
    if(k & (1 << j))
      a = up[a][j];
 
  if(a == b) return a;
 
  for(int j = L; j >= 0; j--)
    if(up[a][j] != up[b][j])
      a = up[a][j], b = up[b][j];
  return up[a][0];
}
 
string solve(int a, int b, int c){
  if(d[c] <= d[lca(a, b)] && (lca(a, c) == c || lca(b, c) == c))
    return "NO";
  return "YES";
}
 
int main(){
  fastio;
  cin >> n >> m >> q;
 
  G.resize(n+1);
  low.resize(n+1);
  pre.resize(n+1);
  T.resize(2*n+1);
  pres.resize(2*n+1);
  posts.resize(2*n+1);
  d.resize(2*n+1);
  L = ceil(log2(2*n));
  up.resize(2*n+1, vector<int>(L+1, 0));
  set<pair<int, int>> E;
 
  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;
    if(E.count({min(a, b), max(a, b)})) continue;
    E.insert({min(a, b), max(a, b)});
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  nr = 0;
  for(int i = 1; i <= n; i++)
    if(!pre[i])
      dfs(i, 0);
 
  //for(int i = 1; i <= n; i++) cout << low[i] << " "; cout << "\n";
  for(int i = 1; i <= n; i++) 
    ae(i, n+low[i]);
  //for(int i = 1; i <= n; i++) cout << sc[i] << " "; cout << "\n";
 
  prid = pstid = 0;
  dfslc(1, 0);
  
  while(q--){
    int a, b, c; cin >> a >> b >> c;
    cout << solve(a, b, c) << "\n";
  }
}
