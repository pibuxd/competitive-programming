// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long n;
vector<long long> a, dp;

int main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  dp.resize(n+1);

  for(long long i = 1; i <= n; i++){
    cin >> a[i];
    long long x = upper_bound(a.begin()+1, a.begin()+i-1, a[i]-90) - a.begin();
    long long y = upper_bound(a.begin()+1, a.begin()+i-1, a[i]-1440) - a.begin();
    dp[i] = min({
      dp[i-1] + 20,
      dp[x-1] + 50,
      dp[y-1] + 120 
    });

    cout << (dp[i] - dp[i-1]) << "\n";
  }
}