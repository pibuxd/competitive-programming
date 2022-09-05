#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n;
vector<int> t, dist, distdo, order, endpoint;
vector<vector<int>> G, revG;
stack<array<int, 3>> S; // {v, x, dist[x]}

void bfs(){
  vector<int> ind(n+1);
  for(int i = 1; i <= n; i++)
    for(int x : G[i])
      ind[x]++;
  queue<int> Q;
  for(int i = 1; i <= n; i++)
    if(ind[i] == 0)
      Q.push(i);
  
  dist.assign(n+1, 0);
  while(!Q.empty()){
    int v = Q.front();
    Q.pop();
    dist[v] += t[v];
    order.push_back(v);

    for(int x : G[v]){
      ind[x]--;
      dist[x] = max(dist[x], dist[v]);
      if(ind[x] == 0)
        Q.push(x);
    }
  }
}

void revbfs(){
  vector<int> ind(n+1);

  for(int i = 1; i <= n; i++)
    for(int x : revG[i])
      ind[x]++;
  queue<int> Q;
  for(int i = 1; i <= n; i++)
    if(ind[i] == 0)
      Q.push(i);
  
  distdo.assign(n+1, 0);
  while(!Q.empty()){
    int v = Q.front();
    Q.pop();
    distdo[v] += t[v];

    for(int x : revG[v]){
      ind[x]--;
      distdo[x] = max(distdo[x], distdo[v]);
      if(ind[x] == 0)
        Q.push(x);
    }
  }
}

int main(){
  fastio;
  cin >> n;
  G.resize(n+1);
  revG.resize(n+1);
  t.resize(n+1);

  for(int i = 1; i <= n; i++){
    int k; cin >> t[i] >> k;
    for(int j = 1; j <= k; j++){
      int v; cin >> v;
      G[v].push_back(i);
      revG[i].push_back(v);
    }
  }
  
  bfs();

  if(order.size() != n){
    cout << "CYKL\n";
    return 0;
  }
  
  revbfs();
  int mxd = 0;
  for(int i = 1; i <= n; i++) mxd = max(mxd, dist[i]);
  //for(int i = 1; i <= n; i++){
    //cout << i << ": " << dist[i] << ", " << distdo[i] << "\n";
  //}
  cout << mxd << "\n";
  int q; cin >> q;
  while(q--){
    int m, d; cin >> m >> d;
    cout << (mxd - dist[m] - distdo[m] + t[m] < d ? "TAK" : "NIE") << "\n";
  }
}
