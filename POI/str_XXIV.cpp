#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n;
vector<vector<int>> G;
vector<int> par, cz;
vector<bool> iscz;

void dfspar(int v, int p){
  par[v] = p;
  for(int x : G[v]){
    if(x == p) continue;
    dfspar(x, v);
  }
}

int main(){
  fastio;
  cin >> n;
  G.resize(n+1);
  par.resize(n+1);
  cz.resize(n+1);
  iscz.resize(n+1);
  
  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfspar(1, 0);
    
  int t; cin >> t;
  int sum = 1;
  while(t--){
    int _z; cin >> _z;
    int z = abs(_z);

    if(_z > 0){
      iscz[z] = true;
      cz[par[z]]++;
      sum += G[z].size() - (cz[z] + iscz[par[z]]) - 1;
    } else{
      iscz[z] = false;
      cz[par[z]]--;
      sum -= G[z].size() - (cz[z] + iscz[par[z]]) - 1;
    }

    cout << sum << "\n";
  }
}
