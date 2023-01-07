// tree
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, d;
vector<vector<int>> G;
vector<bool> A, B;

bool dfsziel(int v, int p, vector<bool> &V, vector<bool> &k){
  bool res = V[v];
  for(int x : G[v])
    if(x != p)
      res |= dfsziel(x, v, V, k);
  if(res) k[v] = true;
  return res;
}

int pathdist(vector<bool> &k){
  int res = 0;
  for(int i = 1; i <= n; i++) 
    if(k[i])
      res++; 
  return res-1;
}

int DFS(int v, int p, int di, int ddep, int currdep, int &res, vector<bool> &V, vector<bool> &k){
  if(k[v]) di = 0;
  if(V[v] && di > d){
    res += di - d;
    ddep = currdep - d;
    di = d;
  }
  for(int x : G[v])
    if(x != p){
      int dd = DFS(x, v, di+1, ddep, currdep+1, res, V, k);
      if(dd > ddep)
        ddep = min(dd, currdep), di = currdep - ddep;
    }
  return ddep;
}

int calcdist(vector<bool> &V, vector<bool> &Y){
  vector<bool> k(n+1, false);
  dfsziel(1, 0, V, k);
  int res = pathdist(k);
  DFS(1, 0, 0, 0, 0, res, Y, k);
  return res;
}

signed main(){
  fastio;
  cin >> n >> d;
  G.resize(n+1);
  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  A.resize(n+1);
  B.resize(n+1);
  int t; cin >> t;
  while(t--){
    int a; cin >> a;
    A[a] = true;
  }
  cin >> t;
  while(t--){
    int b; cin >> b;
    B[b] = true;
  }
  
  int sum = (calcdist(A, B) + calcdist(B, A)) * 2;
  cout << sum << "\n";
}
