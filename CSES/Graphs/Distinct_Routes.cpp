#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<vector<int>> G;
map<array<int, 2>, int> M, istn;
vector<vector<int>> flows;
vector<bool> vis;

bool dfs(int v){
  vis[v] = true;
  if(v == n)
    return true;

  vector<int> todo;

  for(int x : G[v]){
    if(!istn[{v, x}] && M[{x, v}])
      todo.push_back(x);
    if(!(istn[{v, x}] && !M[{v, x}]))
      continue;

    if(!vis[x] && dfs(x)){
      M[{v, x}] = 1;
      return true;
    }
  }

  for(int x : todo){
    if(!vis[x] && dfs(x)){
      M[{x, v}] = 0;
      return true;
    }
  }

  return false;
}

bool _dfs(int v, vector<int> &f){
  if(v == n)
    return true;

  for(int x : G[v]){
    if(M[{v, x}]){
      f.push_back(x);
      M[{v, x}] = 0;
      if(_dfs(x, f))
        return true;
    }
  }

  return false;
}

int main(){
  fastio;
  cin >> n >> m;

  G.resize(n+1);

  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;

    istn[{a, b}] = 1;

    if(!istn[{b, a}]){
      G[a].push_back(b);
      G[b].push_back(a);
    }
  }
  vis.assign(n+1, false);
  while(dfs(1)){ 
    vis.assign(n+1, false);
  }
  for(int x : G[1]){
    if(M[{1, x}]){
      M[{1, x}] = 0;
      vector<int> f({1, x});
      _dfs(x, f);
      flows.push_back(f);
    }
  }

  cout << flows.size() << "\n";
  for(auto f : flows){
    cout << f.size() << "\n";
    for(auto v : f)
      cout << v << " ";
    cout << "\n";
  }
}