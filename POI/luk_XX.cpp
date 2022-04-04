// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Dynamic Programming on tree + binary search
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<vector<int>> G;
vector<int> dp;

int dfs(int v, int p, int k){
  int sum = 0;

  for(int x : G[v]){
    if(x == p) continue;
    sum += dfs(x, v, k) + 1; // +1 as you have to count how many children he has
  }

  return max(0, sum-k);
}

int main(){
  fastio;
  cin >> n;
  G.resize(n+1);

  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int l = 0, r = n, ans = n;
  while(l <= r){
    int m = (l+r)/2;

    if(dfs(1, 0, m) == 0)
      ans = m, r = m-1;
    else
      l = m+1;
  }

  cout << ans;
}