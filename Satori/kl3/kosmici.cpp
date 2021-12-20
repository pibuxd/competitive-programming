#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define INF INT_MAX
#define mxn 10001
#define INF 10000

struct Kosmita {
  int a = 0, b = 0, d = 0;
};

int n, _n;
vector<Kosmita> v;
vector<vector<int>> dp;

int mx(int x, int y){
  if(x > y) swap(x, y);
  int res = 0;
  for(int i = 1; i <= n; i++)
    if(v[i].a <= x && v[i].b <= y)
      res = max(res, v[i].d);  

  return res;
}

int main(){
  fastio;
  // cout << "\n";
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    v.assign(n+1, Kosmita());
    _n = 15;
    dp.assign(_n+2, vector<int>(_n+2, INF));

    for(int i = 1; i <= n; i++){
      cin >> v[i].a >> v[i].b >> v[i].d;
    }
    for(int i = 1; i <= _n; i++)
      dp[i][i] = 0;

    for(int k = 1; k <= _n; k++)
      for(int i = 1; i <= _n; i++)
        for(int j = 1; j <= _n; j++)
          dp[i][j] = dp[i][j] != INF ? min(dp[i][j], dp[i][k] + dp[k][j] + mx(i, j)) : mx(i, j);
        
 
    for(int i = 1; i <= _n; i++) cout << "\t" << i;
    cout << "\n";

    for(int i = 1; i <= _n; i++){
      cout << i << ":\t";
      for(int j = 1; j <= _n; j++){
        cout << dp[i][j] << "\t";
      }
      cout << "\n";
    }
  }
}