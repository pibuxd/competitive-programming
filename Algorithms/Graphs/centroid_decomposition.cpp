// * Centroid Decomposition
// * calculate depth[node] of centroid decomposition tree
// article: https://medium.com/carpanese/an-illustrated-introduction-to-centroid-decomposition-8c1989d53308
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Centroid_Decomposition{
  int n, root;
  vector<vector<int>> G, CDG; // G- input tree, CDG - Centroid Decomposition Tree
  vector<int> sub;
  vector<bool> visited;

  Centroid_Decomposition(int _n){
    n = _n;
    G.resize(n+1);
    CDG.resize(n+1);
    sub.resize(n+1);
    visited.resize(n+1);
  }

  void push(int a, int b){
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int dfs(int v, int p){
    if(visited[v]) return 0;
    sub[v] = 1;
    for(int x : G[v])
      if(x != p)
        sub[v] += dfs(x, v);

    return sub[v];
  }

  int find_centroid(int v, int p, int t_size){
    for(int x : G[v])
      if(!visited[x] && x != p && sub[x] > t_size/2)
        return find_centroid(x, v, t_size);

    return v;
  }

  void build(int v, int p){
    int t_size = dfs(v, p);
    int centroid = find_centroid(v, p, t_size);
    visited[centroid] = true;

    if(p == -1){ // first centroid
      p = centroid;
      root = centroid;
    } else{ // push to Centroid Decomposition Tree
      CDG[centroid].push_back(p);
      CDG[p].push_back(centroid);
    }

    for(int x : G[centroid])
      if(!visited[x])
        build(x, centroid);
  }
};

int main(){
  fastio;
  int n;
  cin >> n;
  Centroid_Decomposition ranks(n); 
  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    ranks.push(a, b);
  }

  ranks.build(1, -1);

  cout << "\n";
  cout << "root:" << ranks.root << "\n";
  for(int i = 1; i <= n; i++){ // print Centroid Decomposition Tree
    cout << i << ": ";
    for(int x : ranks.CDG[i])
      cout << x << " ";
    cout << "\n";
  }
}