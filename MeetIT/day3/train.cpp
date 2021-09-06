#include <bits/stdc++.h>
using namespace std;

const long long INF = LONG_MAX;
int n, m;
vector<vector<pair<int, long long>>> G;
vector<long long> dist1, distn;

bool bfs(int start, int end){
  vector<bool> vis(n+1);
  vis[start] = true;
  queue<int> Q;
  Q.push(start);

  while(!Q.empty()){
    int v = Q.front();
    Q.pop();
    for(auto temp : G[v]){
      int x = temp.first;
      if(x == end)
        return true;
      if(!vis[x]){
        vis[x] = true;
        Q.push(x);
      }
    }
  }

  return false;
}

void dijkstra1(int start){
  vector<bool> vis(n+1);
  vis[start] = true;
  dist1[start] = 0;
  priority_queue<pair<long long, int>> PQ;
  PQ.push({0, start});

  while(!PQ.empty()){
    long long w = -PQ.top().first;
    int v = PQ.top().second;
    PQ.pop();

    if(w != dist1[v])
      continue;

    for(auto x : G[v]){
      if(dist1[x.first] > dist1[v] + x.second){
        dist1[x.first] = dist1[v] + x.second;
        PQ.push({-dist1[x.first], x.first});
      }
    }
  }
}

void dijkstran(int start){
  vector<bool> vis(n+1);
  vis[start] = true;
  distn[start] = 0;
  priority_queue<pair<long long, int>> PQ;
  PQ.push({0, start});

  while(!PQ.empty()){
    long long w = -PQ.top().first;
    int v = PQ.top().second;
    PQ.pop();

    if(w != distn[v])
      continue;

    for(auto x : G[v]){
      if(distn[x.first] > distn[v] + x.second){
        distn[x.first] = distn[v] + x.second;
        PQ.push({-distn[x.first], x.first});
      }
    }
  }
}

int main(){
  cin >> n >> m;
  G.resize(n+1);
  dist1.resize(n+1, INF);
  distn.resize(n+1, INF);

  for(int i = 1; i <= m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back({b, w});
    G[b].push_back({a, w});
  }
  if(!bfs(1, n)){
    cout << "NOPE";
    return 0;
  }
  dijkstra1(1);
  dijkstran(n);

  long long ans = INF;

  for(int i = 1; i <= n; i++){
    for(auto x : G[i]){
      ans = min(ans, dist1[i] + distn[x.first] + 1);
    }
  }

  cout << "DOGE IS HAPPY\n" << ans;
}