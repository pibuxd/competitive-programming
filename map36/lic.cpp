#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

signed main(){
  fastio;

  int q; cin >> q;
  int K = 1;
  int mx = ((long long)1 << 62);

  while(q--){
    char c; int p; cin >> c >> p;

    if(c == '*'){
      if(floor(mx / p) >= K) K *= p;
    } else{
      K /= (K % p == 0 ? p : 1);
    }

    cout << K << "\n";
  }
}
