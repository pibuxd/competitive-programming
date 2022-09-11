#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

struct Edge {
  int v, w; // vierzcholek, waga
  vector<int> potw; // potwory na krawedzi
};

const int pmax = 13, INF = INT_MAX;
int n, m, p, k, N;
vector<vector<Edge>> G;
vector<vector<int>> miecze;

struct XD {
  int w, v; 
  bitset<pmax> b; 
  bool operator< (const XD &x) const {
    return x.w < w;
  }
};

int vw(int v, int w){ // numer wierzchołka 'v' w warstwie 'w'
  return w * n + v;
}

// czy moge przejsc krawedz z bitsetem mieczy
bool canedge(bitset<pmax> &b, vector<int> &potw){
  for(int i : potw)
    if(!b[i-1])
      return false;
  return true;
}

int dijkstra(){
  vector<int> dist(N+1, INF);
  priority_queue<XD> PQ;
  dist[1] = 0;
  PQ.push({0, 1, bitset<pmax>()});

  while(!PQ.empty()){
    auto [t, v, b] = PQ.top(); // t-czas, v-wierzcholek, b-warstwa (bitset)
    PQ.pop();

    if(dist[vw(v, b.to_ulong())] != t) // warunek w dijkstrze
      continue;
                                                 
    for(auto mie : miecze[v]) // dodawanie mieczy do bitseta - wtedy tez sie zmienia warsta
      b[mie-1] = 1;

    for(auto x : G[v]){
      if(!canedge(b, x.potw))
        continue;

      if(t + x.w < dist[vw(x.v, b.to_ulong())]){
        dist[vw(x.v, b.to_ulong())] = t + x.w;
        PQ.push({dist[vw(x.v, b.to_ulong())], x.v, b});
      }
    }
  }
  int mn = INF;
  for(int i = 0; i <= 1<<p; i++)
    mn = min(mn, dist[vw(n, i)]);
  return (mn == INF ? -1 : mn);
}

signed main(){
  fastio;
  cin >> n >> m >> p >> k;

  N = vw(n, (1<<p));
  miecze.resize(n+1);
  G.resize(n+1);

  for(int i = 1; i <= k; i++){
    int w, q; cin >> w >> q;
    for(int j = 1; j <= q; j++){
      int r; cin >> r;
      miecze[w].push_back(r);
    }
  }

  for(int i = 1; i <= m; i++){
    int v, w, t, s; cin >> v >> w >> t >> s;
    vector<int> u(s);
    for(int j = 0; j < s; j++)
      cin >> u[j];
    G[v].push_back({w, t, u});
    G[w].push_back({v, t, u});
  }

  cout << dijkstra() << "\n";
}
