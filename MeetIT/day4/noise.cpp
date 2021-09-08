#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n, k, ans;
vector<ll> a;

int main(){
  fastio;
  cin >> n >> k;
  a.resize(n+1);
  ans = 0;

  for(ll i = 1; i <= n; i++)
    cin >> a[i];
  
  for(ll i = 1; i < n; i++){
    if(a[i] + a[i+1] > k){
      if(a[i] <= k){
        ll temp = k;
        ll val = 0;
        val = temp - a[i];
        ans += a[i+1] - val;
        a[i+1] = val;
      }
      else{
        ans += a[i+1];
        ll temp = k - a[i+1];
        ans += a[i] - k;
        a[i+1] = 0;
      }
    }
  }

  cout << ans;
}