#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, ans;
vector<vector<int>> adj;
vector<bool> done;

void dfs(int v, int p){
  for(int x : adj[v])
    if(x != p){
      dfs(x, v);
      if(!done[x] && !done[v])
        done[x] = done[v] = 1, ans++;
    }
}

int main(){
  fastio;
  cin >> n;
  adj.resize(n+1);
  done.resize(n+1);
  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  ans = 0;
  dfs(1, 0);
  cout << ans;
}