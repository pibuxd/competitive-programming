#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, q, k, INF = LONG_LONG_MAX;
vector<vector<int>> VV;

struct mat{
  vector<vector<int>> V;
  vector<vector<int>> D;

  mat operator * (const mat &m) const {
    mat res;
    res.V.resize(n+1, vector<int>(n+1));
    res.D.resize(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        int x = INF, d = 0;
        for(int t = 1; t <= n; t++){
          if(x > V[t][j] + m.V[i][t] && D[t][j] && m.D[i][t])
            x = V[t][j] + m.V[i][t],
            d = D[t][j] + m.D[i][t];
        }
        res.V[i][j] = x;
        res.D[i][j] = d;
      }
    }
    return res;
  }
};

mat matrixpow(mat &a, int b){
  mat res = a;
  while(b > 0){
    if(b % 2 == 1)
      res = res * a;
    a = a * a;
    b /= 2;
  }
  return res;
}

signed main(){
  fastio;
  cin >> n >> q >> k;
  mat m;
  m.V.resize(n+1, vector<int>(n+1));
  m.D.resize(n+1, vector<int>(n+1));
  
  while(q--){
    int a, b, c; cin >> a >> b >> c;
    m.V[a][b] = c;
    m.D[a][b] = 1;
  }
  VV = m.V;
  m = matrixpow(m, k-1);
  int sum = INF;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(m.D[i][j] == k)
        sum = min(sum, m.V[i][j]);

  if(sum == INF) cout << "IMPOSSIBLE\n";
  else cout << sum << "\n";
}
