#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MX 1000000000

int n, s, m;
vector<int> d;
vector<bool> isstaly;
vector<vector<int>> G;
vector<int> topo;

bool bfs(){
  queue<int> q;
  vector<int> ind(n+1, 0);

  for(int i = 1; i <= n; i++)
    for(int x : G[i])
      ind[x]++;
  
  for(int i = 1; i <= n; i++)
    if(ind[i] == 0){
      q.push(i);
      if(!isstaly[i])
        d[i] = 1;
    }

  while(!q.empty()){
    int v = q.front();
    q.pop();
    topo.push_back(v);

    if(d[v] > MX)
      return false;

    for(int x : G[v]){
      if(isstaly[x] && d[v] >= d[x])
        return false;
      if(!isstaly[x])
        d[x] = max(d[x], d[v] + 1);

      ind[x]--;
      if(ind[x] == 0)
        q.push(x);
      
      if(d[x] > MX)
        return false;
    }
  }

  if(topo.size() != n)
    return false;

  return true;
}

int main(){
  fastio;
  cin >> n >> s >> m;
  
  d.resize(n+1, 0);
  isstaly.resize(n+1, false);
  G.resize(n+1, vector<int>());

  for(int i = 1; i <= s; i++){
    int _p, _d; cin >> _p >> _d;
    d[_p] = _d;
    isstaly[_p] = true;
  }

  for(int i = 1; i <= m; i++){
    int l, r, k; cin >> l >> r >> k;

    vector<int> x(k+1);
    for(int i = 1; i <= k; i++)
      cin >> x[i];
    sort(x.begin(), x.end());

    for(int j = 1; j <= k; j++){
      for(int i = l, id = 1; i <= r; i++){
        if(x[id] == i){
          id++;
          continue;
        }

        G[i].push_back(x[j]);
      }
    }
  }

  bool _b = bfs();

  if(!_b){
    cout << "NIE";
    return 0;
  }

  cout << "TAK\n";
  for(int i = 1; i <= n; i++){
    cout << d[i] << " ";
  }
}