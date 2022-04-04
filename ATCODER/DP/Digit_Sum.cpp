// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define M ((long long)1e9+7)

string K;
int D, k;
vector<array<int, 2>> dp;

int add(int &a, int b){
  a += b;
  if(a >= M)
    a -= M;
}

signed main(){
  fastio;
  cin >> K >> D;
  k = K.size();

  dp.resize(D+1, {0, 0});
  dp[0][0] = 1;

  for(int i = 0; i < k; i++){
    vector<array<int, 2>> _dp(D+1, {0, 0});

    for(int d = 0; d < D; d++){
      for(bool sm_already : {false, true}){
        for(int digit = 0; digit <= 9; digit++){
          if(!sm_already && digit > K[i]-'0')
            break;

          add(_dp[(d+digit)%D][sm_already || (digit < (int)K[i]-'0')], dp[d][sm_already]);
        }
      }  
    }

    dp = _dp; 
  }

  int ans = (dp[0][0] + dp[0][1]) % M;
  ans--;
  if(ans == -1)
    ans = M-1;

  cout << ans;
}