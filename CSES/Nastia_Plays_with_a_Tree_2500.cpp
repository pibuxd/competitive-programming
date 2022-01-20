#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<vector<int>> G;
vector<int> Lleaf, Rleaf, ind; // left and right leaf of union
vector<array<int, 4>> ans; // remove {ans[0], ans[1]}, add {ans[2], ans[3]}
vector<array<int, 2>> del;

int find_leaf(int v, vector<int> &leaf){
  if(leaf[v] == v)
    return v;
  return leaf[v] = find_leaf(leaf[v], leaf);
}

void make_union(int v, int x){
  int Llv = find_leaf(v, Lleaf), Rlv = find_leaf(v, Rleaf);
  int Llx = find_leaf(x, Lleaf), Rlx = find_leaf(x, Rleaf);

  
}

void dfs(int v, int p){
  for(int x : G[v]){
    if(x == p) continue;

    dfs(x, v);

    if(ind[v] > 2){
      del.push_back({v, x});
      // make_union(v, x);
      ind[v]--;
      ind[x]--;
    }
    if(ind[v] == 2 && p > 0){
      del.push_back({p, v});
      // make_union(p, v);
      ind[v]--;
      ind[p]--;
    }
  }
}

void make_set(int v, int p){
  Rleaf[v] = v;

  for(int x : G[v]){
    if(x == p) continue;

    make_set(x, v);
    Rleaf[v] = Rleaf[x];
    if(!Lleaf[v])
      Lleaf[v] = Lleaf[x];
  }

  if(!Lleaf[v])
    Lleaf[v] = v;
}

void solve(){
  for(int i = 1; i <= n; i++)
    ind[i] = G[i].size()-1;

  make_set(1, 0);

  // for(int i = 1; i <= n; i++) cout << Lleaf[i] << " "; cout << "\n";
  // for(int i = 1; i <= n; i++) cout << Rleaf[i] << " "; cout << "\n";

  dfs(1, 0);
  cout << del.size() << "\n";
  if(del.empty()) return;

  int l, r;
  l = Lleaf[del[0][1]];
  r = Rleaf[del[0][1]];
  cout << del[0][0] << " " << del[0][1] << " ";

  cout << r << " " << del[0][0] << "\n";

  for(int i = 1; i < del.size(); i++){ 
    cout << del[i][0] << " " << del[i][1] << " ";

    cout << Rleaf[del[i][1]] << " " << l << "\n";
    l = Lleaf[del[i][1]];
  }
}

int main(){
  fastio;
  int t; cin >> t;

  while(t--){
    cin >> n;
    Lleaf.assign(n+1, 0);
    Rleaf.assign(n+1, 0);
    ind.assign(n+1, 0);
    G.assign(n+1, vector<int>());

    for(int i = 1; i <= n-1; i++){
      int a, b; cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    ans.clear();
    del.clear();
    solve();
  }
}