#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

const ll INF = LONG_MAX;
ll n, k;
vector<ll> in;

int main(){
  fastio;
  cin >> n >> k;
  in.resize(n+1);

  indexed_set S;

  ll ans = 0, l = 1, inv = 0;
  for(ll r = 1; r <= n; r++){
    ll x;
    cin >> x;
    in[r] = x;
    S.insert({-x, r});
    ll it = S.order_of_key({-x, -INF});
    inv += it;

    while(inv > k && l <= r){
      ll _it = S.order_of_key({-in[l], INF});
      inv -= (r-l) - _it+1;
      S.erase({-in[l], l});
      it = S.order_of_key({-x, -INF});
      l++;
    }

    ll len = r-l+1;
    ans += len;
  }

  cout << ans;
}