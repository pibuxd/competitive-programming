// only 2-SAT problem
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, m, nr, mxn;
vector<vector<int>> G, Grev;
vector<bool> vis;
vector<int> scc, order;

void addedge(int a, int b){
  G[a^1].push_back(b);
  G[b^1].push_back(a);
  Grev[a].push_back(b^1);
  Grev[b].push_back(a^1);
}

void dfs(int v){
  vis[v] = true;
  for(int x : G[v])
    if(!vis[x])
      dfs(x);
  order.push_back(v);
}

void dfs2(int v){
  vis[v] = true;
  scc[v] = nr;
  for(int x : Grev[v])
    if(!vis[x])
      dfs2(x);
}

int main(){
  fastio;
  cin >> n >> m;
  mxn = 2*(2*n)+1;
  G.resize(mxn+1);
  Grev.resize(mxn+1);

  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;
    addedge(2*a+1, 2*b+1);
  }
  for(int i = 1; i <= n; i++)
    addedge(2*(2*i-1), 2*(2*i)), addedge(2*(2*i-1)+1, 2*(2*i)+1);

  vis.assign(mxn+1, false);
  for(int i = 1; i <= mxn; i++)
    if(!vis[i])
      dfs(i);
  reverse(all(order));
  vis.assign(mxn+1, false);
  scc.assign(mxn+1, 0);
  nr = 1;

  for(int v : order)
    if(!vis[v])
      dfs2(v), nr++;
    
  vector<int> ans;
  for(int i = 1; i <= 2*n; i++)
    if(scc[2*i] == scc[2*i+1]){
      cout << "NIE\n";
      return 0;
    }

  for(int i = 1; i <= 2*n; i++)
    if(scc[2*i] > scc[2*i+1])
      ans.push_back(i);
  
  for(int a : ans)
    cout << a << "\n";
}
