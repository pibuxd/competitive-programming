#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<vector<int>> adj;
vector<int> sub;

int dfs(int v, int p){
  sub[v] = 1;
  for(int x : adj[v])
    if(x != p)
      sub[v] += dfs(x, v);

  return sub[v];
}

int centroid(int v, int p){
  for(int x : adj[v])
    if(x != p && sub[x] > n/2)
      return centroid(x, v);

  return v;
}

int main(){
  fastio;
  cin >> n;
  adj.resize(n+1);
  sub.resize(n+1);

  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, 0);
  cout << centroid(1, 0);
}