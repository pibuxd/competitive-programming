// * find bridges and articulation points in undirected graph
// calculate low
int n, nr;
vector<int> low, pre, vis;
vector<vector<int>> G;

void dfs(int v, int p){
  pre[v] = low[v] = ++nr;
  int children = 0;

  for(int x : G[v]){
    if(x == p) continue;
    if(!vis[x]){
      children++;
      dfs(x, v);
      low[v] = min(low[v], low[x]);
      if(low[x] > pre[v]) // low[x] == pre[x]
        bridge(x, v);
      if(low[x] >= pre[v] && p)
        articulation_point(v);
    } else{
      low[v] = min(low[v], pre[x]);
    }
  }
  if(!p && children > 1)
    articulation_point(v);
}

int main(){ 
  low.assign(n+1, 0);
  pre.assign(n+1, 0);
  vis.assign(n+1, false);
  nr = 0;
  for(int i = 1; i <= n; i++)
    if(!vis[i])
      dfs(i, 0);
}
