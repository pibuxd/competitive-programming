#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, m;
vector<vector<int>> G, Gdag;
vector<int> cap, order;
vector<bool> visited;

bool bfs(){
  queue<int> Q;
  Q.push(1);
  vector<int> ind(n+1), indused(n+1);

  for(int i = 1; i <= n; i++)
    for(int x : G[i])
      ind[x]++;
  indused[1] = ind[1];
  indused[2] = ind[2];
  int vis = 0;
  while(!Q.empty()){
    int v = Q.front();
    Q.pop();
    vis++;
    //cout << v << "\n";
    for(int x : G[v]){
      Gdag[v].push_back(x);
      indused[x]++;
      if(indused[x]*2 == ind[x]){
        Q.push(x);
      }
    }
  }
  return (vis == n-1);
}

void dfs(int v){
  visited[v] = true;
  for(int x : Gdag[v])
    if(!visited[x])
      dfs(x);
  order.push_back(v);
}

int main(){
  fastio;
  cin >> n >> m;
  G.resize(n+1);
  Gdag.resize(n+1);
  cap.resize(n+1);
  
  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  bool ok = bfs();
  if(!ok){
    cout << "NIE\n";
    return 0;
  }
  cout << "TAK\n";
  visited.assign(n+1, false);
  dfs(1);
  reverse(all(order));

  int nr = 1;
  for(int v : order)
    cap[v] = nr++;

  for(int i = 1; i <= n; i++)
    cout << cap[i] << " ";
  cout << "\n";
}
