#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n, sum;
vector<ll> a;

int main(){
  fastio;
  ll t;
  cin >> t;

  while(t--){
    cin >> n >> sum;
    a.assign(n+1, 0);

    ll l = 1, r = 1;
    ll _l = -321, _r = -312321;
    
    for(l = 1, r = 1; r <= n; r++){
      cin >> a[r];
      sum += a[r];

      while(l <= r && sum < 0){
        sum -= a[l];
        l++;
      }

      if(r-l > _r-_l)
        _l = l, _r = r; 
    }

    if(_l > _r)
      cout << "-1\n";
    else
      cout << _l << " " << _r << "\n";
  }
}