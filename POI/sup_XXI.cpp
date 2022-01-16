#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, q, ds;
vector<int> k, p, d;
vector<vector<int>> G;

int is_leaf(int v){
  return G[v].size() == 1;
}

void merge_q(priority_queue<array<int, 2>> &q, queue<array<int, 2>> &q2){
  while(!q2.empty()){
    q.push(q2.front());
    q2.pop();
  }
}

void dfs(int v, int p, int dep){
  ds = max(ds, dep);
  d[dep]++;
  for(int x : G[v])
    if(x != p)
      dfs(x, v, dep + 1);
}

void qry(int &ans, int r, int i, int val){
  if(i > ds && val == 0)  
    return;
  ans++;

  if(i <= ds)
    val += d[i];
  
  val = max(0, val-r);
  qry(ans, r, i+1, val);
}

signed main(){
  fastio;
  cin >> n >> q;
  k.resize(n+1);
  p.resize(n+1);
  d.resize(n+1);
  G.resize(n+1);

  for(int i = 1; i <= q; i++) cin >> k[i];

  for(int i = 2; i <= n; i++){
    cin >> p[i];
    G[i].push_back(p[i]);
    G[p[i]].push_back(i);
  }

  ds = 0;
  d.push_back(0);
  dfs(1, 0, 1);

  for(int i = 1; i <= q; i++){
    int ans = 0;
    qry(ans, k[i], 1, 0);
    cout << ans << " ";
  }
}