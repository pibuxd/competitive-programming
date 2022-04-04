// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct xd {
  ll d;
  int node, p; // p: 1 - p, 2 - np
};

struct comp {
  bool operator()(const xd& left, const xd& right){
    return left.d > right.d;
  }
};

const ll INF = LONG_MAX;
int n, m, st, e;
vector<vector<pair<int, ll>>> G;
vector<ll> distp, distnp, dist;

void dijkstra(){
  distp[st] = distnp[st] = 0;
  priority_queue<xd, vector<xd>, comp> PQ;
  PQ.push({0, st, 1});

  while(!PQ.empty()){
    auto t = PQ.top();
    ll w = t.d;
    int v = t.node, p = t.p;
    PQ.pop();

    if(p == 1 && w != distp[v]) continue;
    if(p == 2 && w != distnp[v]) continue;

    for(auto x : G[v]){
      if(p == 1){
        if(distnp[x.first] > distp[v] + x.second){
          distnp[x.first] = distp[v] + x.second;
          PQ.push({distnp[x.first], x.first, 2});
        }
      } else{ // p == 2
        if(distp[x.first] > distnp[v] + x.second){
          distp[x.first] = distnp[v] + x.second;
          PQ.push({distp[x.first], x.first, 1});
        }
      }
    }
  }
}

int main(){
  cin >> n >> m;

  G.resize(n+1);
  distp.resize(n+1, INF);
  distnp.resize(n+1, INF);

  for(int i = 0; i < m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back({b, w});
    G[b].push_back({a, w});
  }

  cin >> st >> e;

  dijkstra();
  
  if(distp[e] == INF) distp[e] = -1;
  if(distnp[e] == INF) distnp[e] = -1;
  cout << distp[e] << " " << distnp[e];
}