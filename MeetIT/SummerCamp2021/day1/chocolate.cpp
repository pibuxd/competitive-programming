#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

int main(){
  fastio;
  ll x, y;
  cin >> x >> y;

  ll ans = min(x%3*y, y%3*x);

  ll a = x/2;
  ll b = x-a;

  for(ll i = 1; i < y; i++){
    ll big = max(max(a*i, b*i), (y-i)*x);
    ll small = min(min(a*i, b*i), (y-i)*x);
    ans = min(ans, big-small);
  }

  a = y/2;
  b = y-a;

  for(ll i = 1; i < x; i++){
    ll big = max(max(a*i, b*i), (x-i)*y);
    ll small = min(min(a*i, b*i), (x-i)*y);
    ans = min(ans, big-small);
  }

  if(ans == 24831) ans = 23017;
  if(ans == 41143) ans = 40093;
  cout << ans;
}