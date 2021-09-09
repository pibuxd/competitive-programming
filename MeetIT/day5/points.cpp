#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

ll n;
vector<ll> x, y;

ll check(ll val){
  ll ans = 0;

  for(ll i = 1; i <= n; i++){
    ans += abs(y[i]-val);
    val++;
  }

  return ans;
}

int main(){
  fastio;
  cin >> n;
  x = y = vector<ll>(n+1);

  for(ll i = 1; i <= n; i++){
    cin >> x[i] >> y[i];
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  ll med = x[(n/2)], ans = 0;

  for(ll i = 1; i <= n; i++){
    ans += abs(med-x[i]);
  }
  
  ll l = 1, r = 10e9;

  ll res = 0;
  while(l <= r){
    ll m = (l+r)/2;
    ll c = check(m), c1 = check(m+1);

    if(c <= c1){
      res = c;
      r = m-1;
    }
    else{
      l = m+1;
    }
  }

  cout << ans+res;
}