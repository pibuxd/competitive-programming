#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(x) x.begin(), x.end()
#define LOG 17
#define INF (int)(1e18)

int n, r;
vector<int> t, dk, dep, vr, ds1, ds2, ds3, ds4, ds5;
vector<vector<int>> up, d1up, d2up, d3up, d4up, d5up, R;
vector<vector<array<int, 2>>> G;

void dfs(int v, int p){
  up[v][0] = p;

  for(auto x : G[v]){
    if(x[0] == p)
      continue;

    up[x[0]][0] = v;
    dep[x[0]] = dep[v] + 1;
    dk[x[0]] = dk[v] + x[1];
    dfs(x[0], v);
  }
}

void bfs(const vector<int> &S, vector<int> &ds){
  priority_queue<array<int, 2>> q;
  for_each(all(S), [&q, &ds](int i){ q.push({0, i}); ds[i] = 0; });

  while(!q.empty()){
    int w = -q.top()[0];
    int v = q.top()[1];
    q.pop();

    if(ds[v] != w)
      continue;  

    for(auto x : G[v]){
      if(ds[x[0]] > ds[v] + x[1]){
        ds[x[0]] = ds[v] + x[1];
        q.push({-ds[x[0]], x[0]});
      }
    }
  }
}

void build(){
  dfs(1, 0);

  for(int k = 1; k <= LOG; k++)
    for(int i = 1; i <= n; i++)
      up[i][k] = up[up[i][k-1]][k-1];

  sort(all(vr), [](int a, int b){ return R[a].size() > R[b].size(); });

  bfs(R[vr[0]], ds1);
  if(vr.size() >= 2)
    bfs(R[vr[1]], ds2);
  if(vr.size() >= 3)
    bfs(R[vr[2]], ds3);
  if(vr.size() >= 4)
    bfs(R[vr[3]], ds4);
  if(vr.size() >= 5)
    bfs(R[vr[4]], ds5);

  for(int i = 1; i <= n; i++){
    d1up[i][0] = min(ds1[i], ds1[up[i][0]]);
    d2up[i][0] = min(ds2[i], ds2[up[i][0]]);
    d3up[i][0] = min(ds3[i], ds3[up[i][0]]);
    d4up[i][0] = min(ds4[i], ds4[up[i][0]]);
    d5up[i][0] = min(ds5[i], ds5[up[i][0]]);
  }

  for(int k = 1; k <= LOG; k++)
    for(int i = 1; i <= n; i++){
      d1up[i][k] = min(d1up[i][k-1], d1up[up[i][k-1]][k-1]);
      d2up[i][k] = min(d2up[i][k-1], d2up[up[i][k-1]][k-1]);
      d3up[i][k] = min(d3up[i][k-1], d3up[up[i][k-1]][k-1]);
      d4up[i][k] = min(d4up[i][k-1], d4up[up[i][k-1]][k-1]);
      d5up[i][k] = min(d5up[i][k-1], d5up[up[i][k-1]][k-1]);
    }
  
}

int lca(int a, int b){
  if(dep[a] < dep[b])
    swap(a, b);

  int k = dep[a] - dep[b];

  for(int i = 0; i <= LOG; i++)
    if((k >> i) & 1)
      a = up[a][i];
  
  if(a == b)
    return a;

  for(int i = LOG; i >= 0; i--)
    if(up[a][i] != up[b][i])
      a = up[a][i], b = up[b][i];
  
  return up[a][0];
}

int d(int a, int b){
  return dk[a] + dk[b] - 2*dk[lca(a, b)];
}

int d(int a, int b, int c){
  return d(a, c) + d(b, c);
}

int r2(int a, int b, int c, const vector<vector<int>> &dup, const vector<int> &ds){
  int dist = d(a, b);
  int res = INF;

  if(dep[a] < dep[b])
    swap(a, b);
  
  int k = dep[a] - dep[b];

  if(a == b)
    return 2 * ds[a];

  for(int i = 0; i <= LOG; i++)
    if((k >> i) & 1)
      res = min(res, dup[a][i]), a = up[a][i];

  if(a == b)
    return 2 * res + dist;
  
  for(int i = LOG; i >= 0; i--)
    if(up[a][i] != up[b][i])
      res = min({res, dup[a][i], dup[b][i]}), 
      a = up[a][i], 
      b = up[b][i];
  
  return 2 * min({res, dup[a][0], dup[b][0]}) + dist;
}

int qry(int a, int b, int c){
  if(R[c].empty())
    return -1;

  if(vr.size() == 1)
    return d(a, b, b);
  
  if(c == vr[0])
    r2(a, b, c, d1up, ds1);
  else if(vr.size() >= 2 && c == vr[1])  
    r2(a, b, c, d2up, ds2);
  else if(vr.size() >= 3 && c == vr[2])  
    r2(a, b, c, d3up, ds3);
  else if(vr.size() >= 4 && c == vr[3])  
    r2(a, b, c, d4up, ds4);
  else if(vr.size() >= 5 && c == vr[4])  
    r2(a, b, c, d5up, ds5);

  int mn = INF;
  for(int x : R[c])
    mn = min(mn, d(a, b, x));
  
  return mn;
}

void init();

signed main(){
  fastio;
  cin >> n >> r;
  init();

  for(int i = 1; i <= n; i++){
    int x; cin >> x;
    if(R[x].empty())
      vr.push_back(x);

    R[x].push_back(i);
  }

  for(int _ = 1; _ <= n-1; _++){ 
    int a, b, c; cin >> a >> b >> c; G[a].push_back({b, c}); G[b].push_back({a, c});
  }

  build();

  int q; cin >> q;
  while(q--){
    int a, b, c; cin >> a >> b >> c;
    cout << qry(a, b, c) << "\n";
  }
}

void init(){
  t.resize(n+1);
  dk.resize(n+1);
  dep.resize(n+1);
  G.resize(n+1);
  R.resize(r+1);
  up.resize(n+1, vector<int>(LOG+1));

  ds1.resize(n+1, INF);
  ds2.resize(n+1, INF);
  ds3.resize(n+1, INF);
  ds4.resize(n+1, INF);
  ds5.resize(n+1, INF);

  d1up.resize(n+1, vector<int>(LOG+1, INF));
  d2up.resize(n+1, vector<int>(LOG+1, INF));
  d3up.resize(n+1, vector<int>(LOG+1, INF));
  d4up.resize(n+1, vector<int>(LOG+1, INF));
  d5up.resize(n+1, vector<int>(LOG+1, INF));
}