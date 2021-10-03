#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int INF = INT_MAX;
int n, m;
vector<vector<array<int, 2>>> G;
vector<int> dist, ans;
vector<bool> vis;

void dijkstra(){
  dist.assign(n+1, INF);
  dist[1] = 0;
  priority_queue<array<int, 2>> pq;
  pq.push({0, 1});

  while(!pq.empty()){
    auto node = pq.top();
    int v = node[1], w = -node[0];
    pq.pop();

    if(dist[v] != w)
      continue;
    
    for(auto x : G[v])
      if(dist[v] + x[1] < dist[x[0]]){
        dist[x[0]] = dist[v] + x[1];
        pq.push({-dist[x[0]], x[0]});
      }
  }
}

void dfs(int v){
  vis[v] = true;
  ans.push_back(v);

  for(auto x : G[v])
    if(!vis[x[0]]){
      if(dist[x[0]] + x[1] == dist[v]){
        dfs(x[0]);
      }
    }
}

int main(){
  fastio;
  cin >> n >> m;
  G.resize(n+1);

  for(int i = 1; i <= m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }

  dijkstra();

  vis.assign(n+1, false);
  dfs(n);
  
  sort(ans.begin(), ans.end());
  for(int x : ans)
    cout << x << "\n";
}