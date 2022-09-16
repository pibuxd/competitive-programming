#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int unsigned int

int n, m, k, q, INF = UINT_MAX; 
vector<vector<pair<int, int>>> G;
vector<vector<int>> D;
vector<int> bef, dn;

void gen(int b, int bs, int popcnt, vector<vector<int>> &com){
  if(bs == k){
    com[popcnt].push_back(b);
    return;
  }
  gen(b, bs+1, popcnt, com);
  gen(b+(1<<bs), bs+1, popcnt+1, com);
}

vector<int> dijkstra(int start){
  vector<int> dist(n+1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
  dist[start] = 0;
  PQ.push({0, start});

  while(!PQ.empty()){
    auto [d, v] = PQ.top();
    PQ.pop();
    if(dist[v] != d) continue;
    for(auto [x, w] : G[v])
      if(dist[x] > d+w){
        dist[x] = d+w;
        PQ.push({d+w, x});
      }
  }
  return dist;
}

void newmap(unordered_map<int, vector<int>> &M, int s, int val, vector<vector<int>> &com){
  M.clear();
  for(int c : com[s])
    M[c].assign(k+1, val);
}

int solve(){
  vector<vector<int>> com(k+1);
  gen(0, 0, 0, com);
  unordered_map<int, vector<int>> dist1, dist2;
  newmap(dist1, 0, 0, com);
  newmap(dist2, 1, INF, com);

  for(int i = 1; i <= k; i++){
    for(int c : com[i])
      for(int v = 1; v <= k; v++)
        for(int w = 1; w <= k; w++){
          int w2 = 1<<w-1;
          if((c & w2) == w2 && (c & bef[v]) == bef[v] && dist1[c-w2][w] != INF)
            dist2[c][v] = min(dist2[c][v], dist1[c-w2][w] + D[w][v]);
        }
    swap(dist1, dist2);
    if(i < k)
      newmap(dist2, i+1, INF, com);
  }

  int mn = INF;
  for(int i = 1; i <= k; i++)
    mn = min(mn, dist1[(1<<k)-1][i] + dn[i]);
  return mn;
}

signed main(){
  fastio;
  cin >> n >> m >> k;
  k++;
  G.resize(n+1);
  bef.resize(k+1, 1);

  for(int i = 1; i <= m; i++){
    int a, b, w; cin >> a >> b >> w;
    G[a].push_back({b, w});
    G[b].push_back({a, w});
  }

  cin >> q;
  for(int i = 1; i <= q; i++){
    int a, b; cin >> a >> b;
    bef[b] += (1<<a-1);
  }
  D.assign(k+1, vector<int>(k+1, 0));
  for(int i = 1; i < k; i++){
    vector<int> d = dijkstra(i);
    for(int j = i + 1; j <= k; j++)
      D[i][j] = D[j][i] = d[j];
  }
  dn = dijkstra(n);
  G.clear();

  cout << solve() << "\n";
}
