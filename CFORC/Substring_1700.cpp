// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, cnt, ans;
vector<int> s, ind;
vector<vector<int>> G, f;

vector<int> _merge(const vector<int> &x, const vector<int> &y){
  vector<int> _ans(26);
  for(int i = 0; i < 26; i++){
    _ans[i] = max(x[i], y[i]);
    ans = max(ans, _ans[i]);
  }
  return _ans;
}

void bfs(){
  cnt = 0;
  ans = 1;
  queue<int> Q;
  for(int i = 1; i <= n; i++)
    if(!ind[i])
      Q.push(i), f[i][s[i]] = 1;
  
  while(!Q.empty()){
    int v = Q.front();
    Q.pop();
    cnt++;

    for(int x : G[v]){
      f[x] = _merge(f[v], f[x]);
      ind[x]--;
      if(!ind[x]){
        f[x][s[x]]++;
        ans = max(ans, f[x][s[x]]);
        Q.push(x);
      }
    }
  }
}

int main(){
  fastio;
  cin >> n >> m;
  s.resize(n+1);
  ind.resize(n+1);
  G.resize(n+1);
  f.resize(n+1, vector<int>(26));

  for(int i = 1; i <= n; i++){
    char c;
    cin >> c;
    s[i] = (int)c - 97;
  }
  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    ind[b]++;
  }

  bfs();
  if(cnt < n)
    cout << -1;
  else
    cout << ans;
}