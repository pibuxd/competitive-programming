#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

signed main(){
  fastio;

  int n, k; cin >> n >> k;

  int ans = 1;

  if(k >= 2) ans += (n-1)*n/2;
  if(k >= 3) ans += (n-2)*(n-1)*n/3;
  if(k == 4) ans += (n-3)*(n-2)*(n-1)*n/8*3;

  cout << ans << "\n";
}
