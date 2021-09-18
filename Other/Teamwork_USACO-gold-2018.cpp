#include <bits/stdc++.h>
using namespace std;

int main(){
  ifstream in; ofstream out; in.open("teamwork.in"); out.open("teamwork.out");
  int n, k;
  in >> n >> k;
  vector<int> a(n+1), dp(n+1);

  for(int i = 1; i <= n; i++)
    in >> a[i];

  dp[1] = a[1];
  for(int i = 2; i <= n; i++){
    int mx = a[i];

    for(int j = i; j >= 1 && i-j+1 <= k; j--){
      mx = max(mx, a[j]);
      if(j == 1)
        dp[i] = max(dp[i], mx*(i - j + 1));
      else
        dp[i] = max(dp[i], dp[j-1] + mx*(i - j + 1));
    }
  }

  out << dp[n] << "\n";
}