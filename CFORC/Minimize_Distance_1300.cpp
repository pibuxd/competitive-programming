#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
typedef long long ll;

ll n, k;
vector<ll> a, b;

ll solve(){
  sort(all(a));
  sort(all(b));
  int it_a = a.size()-1, it_b = b.size()-1;
  ll res = 0;
  if(!a.empty()) res = -a[it_a];
  else if(!b.empty()) res = -b[it_b];
  if(!a.empty() && !b.empty()) res = -max(a[it_a], b[it_b]);

  while(1){
    if((it_a >= 0 && it_b >= 0 && a[it_a] >= b[it_b]) || (it_b < 0 && it_a >= 0)){
      // cout << a[it_a] << ", ";
      res += a[it_a] * 2, it_a -= k;

    } else if((it_a >= 0 && it_b >= 0 && a[it_a] < b[it_b]) || (it_b >= 0 && it_a < 0)){
      // cout << b[it_b] << ", ";
      res += b[it_b] * 2, it_b -= k;

    } else if(it_a < 0 && it_b < 0)
      break;
  }

  return res;
}

signed main(){
  fastio;
  ll t;
  cin >> t;
  while(t--){
    a = b = vector<ll>();
    a.clear();
    b.clear();
    cin >> n >> k;
    ll _n = 0;
    for(ll i = 1; i <= n; i++){
      ll x;
      cin >> x;
      if(x > 0) a.push_back(x);
      else b.push_back(abs(x));
      _n++;
    }
    n = _n;

    cout << solve() << "\n";
  }
}