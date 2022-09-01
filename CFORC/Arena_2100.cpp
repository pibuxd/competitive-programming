#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n, x, M = 998244353;
vector<int> fac;
vector<vector<int>> dp;

void prefac(){
  fac.assign(n+1, 0);
  fac[0] = 1;
  for(int i = 1; i <= n; i++)
    fac[i] = (fac[i-1]*i)%M;
}

int quickpow(int a, int b){
  int res = 1;
  while(b > 0){
    if(b % 2 == 1)
      res = (res*a)%M;
    a = (a*a)%M;
    b /= 2;
  }
  return res;
}

int divmod(int a, int b){
  return (a*quickpow(b, M-2))%M;
}

int newton(int a, int b){
  return divmod(fac[a], (fac[b]*fac[a-b])%M);
}
  
signed main(){
  cin >> n >> x;

  prefac();
  dp.assign(n+1, vector<int>(x+1, 0));
  dp[n][0] = 1;

  for(int i = n; i > 1; i--){
    for(int j = 0; j < x; j++){
      if(!dp[i][j]) continue;
      for(int k = i; k >= 0; k--){
        int nj = min(x, j+i-1);
        dp[k][nj] = (dp[k][nj]+((dp[i][j]*newton(i, i-k))%M)*quickpow(nj-j, i-k))%M;
      }
    }
  }

  int sum = 0;
  for(int j = 0; j <= x; j++)
    sum = (sum + dp[0][j])%M;
  cout << sum << "\n";
}
