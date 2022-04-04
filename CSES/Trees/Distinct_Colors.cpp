// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> ans;
vector<vector<int>> G;
vector<bool> vis;
vector<set<int>> S;

void dfs(int v, int p){

  for(int x : G[v])
    if(x != p){
      dfs(x, v);
      int a = v, b = x;
      if(S[a].size() < S[b].size())
        swap(S[a], S[b]);
      for(int i : S[b]) S[a].insert(i);
    }
  
  ans[v] = S[v].size();
}

int main(){
  fastio;
  cin >> n;

  vis.resize(n+1);
  ans.resize(n+1);
  G.resize(n+1);
  S.resize(n+1);
  
  for(int i = 1; i <= n; i++){
    int c;
    cin >> c;
    S[i].insert(c);
  }

  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0);

  for(int i = 1; i <= n; i++)
    cout << ans[i] << " ";
}