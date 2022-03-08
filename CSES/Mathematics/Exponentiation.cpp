// * Quick power with modulo
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define MOD (int)(1e9+7)

int quick_power(int a, int b){
  int ans = 1;

  while(b > 0){
    if(b % 2 == 1)
      ans = (ans * a) % MOD;
    b /= 2;
    a = (a * a) % MOD;
  }

  return ans;
}

signed main(){
  fastio;
  int t; cin >> t;
  while(t--){
    int a, b; cin >> a >> b;
    cout << quick_power(a, b) << "\n";
  }
}