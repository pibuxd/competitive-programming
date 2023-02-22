#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, sum;
vector<int> a, C, D, SUB, S;
vector<vector<int>> G;

void dfs(int v, int p){
  SUB[v] = 1;
  D[v] = a[v];
  S[v] = a[v];

  for(int x : G[v]){
    if(x == p) continue;
    dfs(x, v);
    sum += (D[x] + S[x]) * (n-SUB[x]);
    D[v] += S[x] + D[x]; 
    SUB[v] += SUB[x];
    S[v] += S[x];
  }
}

int main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  G.resize(n+1);
  C.resize(n+1);
  D.resize(n+1);
  SUB.resize(n+1);
  S.resize(n+1);

  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  sum = 0;
  dfs(1, 0);
  cout << sum << "\n";
}
