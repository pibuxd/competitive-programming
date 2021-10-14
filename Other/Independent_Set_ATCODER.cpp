#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MOD = 1000000007;
int n;
vector<vector<int>> G;
vector<long long> black, white;

void dfs(int v, int par){
  black[v] = white[v] = 1;
  for(int x : G[v]){
    if(x == par) continue;
    dfs(x, v);
    black[v] = (black[v] * white[x]) % MOD;
    white[v] = (white[v] * (black[x] + white[x])) % MOD;
  }
}

int main(){
  fastio;
  cin >> n;
  G.resize(n+1);
  black.resize(n+1);
  white.resize(n+1);

  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0);
  cout << (black[1] + white[1]) % MOD;
}