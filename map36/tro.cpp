#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n, k, sqk, ans, M = 1e9+7;

int komb(int x){
  if(x > n) return 0;
  return (n-x+1);
}

void dziel(){
  for(int i = 1; i <= sqk; i++){
    if(k % i == 0 && i != k/i)
      ans = (ans + (2*(komb(i)*komb(k/i))%M)%M)%M;
    else if(k % i == 0 && i == k/i)
      ans = (ans + (1*(komb(i)*komb(k/i))%M)%M)%M;
      
  }
}

signed main(){
  fastio;
  cin >> n >> k;

  ans = 0;
  k *= 2;
  sqk = sqrt(k);
  
  dziel();
  ans = (ans*4)%M;

  cout << ans << "\n";
}
