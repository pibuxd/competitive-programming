#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n, a, b, ans;
vector<ll> h;

bool check(ll x){
  ll _a = a-b;
  ll _x = 0;

  for(ll i = 1; i <= n; i++){
    ll t = h[i] - x*b;
    if(t > 0){
      _x += t/_a;
      if(t % _a != 0)
        _x++;
    }
  }
  return _x <= x;
}

void bin_search(){
  ll l = 1, r = 10e9, m;

  while(l <= r){
    m = (l+r)/2;
    bool ok = check(m);

    if(ok){
      ans = m;
      r = m-1;
    }
    else
      l = m+1;
  }
}

int main(){
  fastio;
  cin >> n >> a >> b;
  ans = 0;
  h.resize(n+1);

  for(ll i = 1; i <= n; i++)
    cin >> h[i];

  bin_search();
  // if(check(3))
  //   cout << "\nyes\n";
  cout << ans;
}