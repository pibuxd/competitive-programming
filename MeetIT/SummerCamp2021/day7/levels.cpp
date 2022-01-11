#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n, m;
vector<ll> p;

ll check(ll k){
  ll ans = 0;

  for(ll i = 2; i <= n; i++){
    if(p[i] == p[i-1]) continue;
    
    else if(p[i] > p[i-1]){
      if(k > p[i-1] && k <= p[i]){
        ans++;
        ans += p[i] - k;
      }
      else{
        ans += p[i] - p[i-1];
      }
    }

    else if(p[i] < p[i-1]){
      if(k <= p[i]){
        ans++;
        ans += p[i] - k;
        continue;
      }
      if(k > p[i-1]){
        ans++;
        ans += m - k;
        ans++;
        ans += p[i] - 1;
      }
      else{
        ans += m - p[i-1];
        ans++;
        ans += p[i] - 1;
      }
    }
  }

  return ans;
}

int main(){
  fastio;
  cin >> n >> m;
  p.resize(n+1);

  for(ll i = 1; i <= n; i++)
    cin >> p[i];

  ll ans = LONG_MAX;

  if(n <= 1000)
    for(ll i = 1; i <= n; i++){
      ans = min(ans, check(p[i]));
    }
  else
    for(ll i = 1; i <= m; i++){
      ans = min(ans, check(i));
    }

  // for(int i = 1; i <= n; i++){
  //   cout << check(p[i]) << "\n";
  // }

  cout << ans;
}
