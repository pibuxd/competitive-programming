// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
int n;
vector<vector<int>> G;
vector<bool> vis;
vector<int> topo;
 
void dfs(int v){
  vis[v] = true;
  for(int x : G[v])
    if(!vis[x])
      dfs(x);
 
  topo.push_back(v);
}
 
void topo_sort(){
  for(int i = 1; i <= n; i++)
    if(!vis[i])
      dfs(i);
 
  reverse(topo.begin(), topo.end());
}
 
int main(){
  fastio;
  int t; cin >> t;
 
  while(t--){
    n = 0;
    map<int, int> com;
    vector<pair<int, int>> edges;
    set<int> S;
 
    int _t; cin >> _t;
 
    while(_t--){
      int z; cin >> z;
      vector<int> a(z);
 
      for(int &i : a){
        cin >> i; S.insert(i);
      }
      for(int i = 1; i < z; i++)
        edges.push_back({a[i-1], a[i]});
 
      for(int s : S){
        if(!com[s]){
          n++;
          com[s] = n;
        }
      }
 
      S.clear();
    }
 
    // cout << " n = " << n << "\n";
    G.assign(n+1, vector<int>());
 
    for(auto e : edges){
      G[com[e.first]].push_back(com[e.second]);
      // cout << com[e.first] << " -> " << com[e.second] << "\n";
    }
    vis.assign(n+1, false);
    topo.clear();
    topo_sort();
 
    vector<int> ind(n+1);
    for(int i = 1; i <= n; i++)
      ind[topo[i-1]] = i;
 
    string ans = "TAK";
 
    for(int i = 1; i <= n; i++)
      for(int j : G[i])
        if(ind[j] <= ind[i])
          ans = "NIE";
 
    cout << ans << "\n";
  }
}