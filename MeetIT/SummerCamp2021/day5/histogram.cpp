// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n, q;
vector<ll> v;

ll calc(ll low, ll high){
  vector<ll> l(n+1, low-1), r(n+1);
  stack<ll> S;
  S.push(high);
  for(ll i = high-1; i >= low; i--){
    while(!S.empty()){
      ll x = S.top();
      if(v[i] < v[x]){
        S.pop();
        l[x] = i;
      }
      else
        break;
    }
    S.push(i);
  }

  S = stack<ll>();
  S.push(low);
  for(ll i = low+1; i <= high; i++){
    while(!S.empty()){
      ll x = S.top();
      if(v[i] < v[x]){
        S.pop();
        r[x] = i;
      }
      else
        break;
    }
    S.push(i);
  }

  long long ans = 0;
  for(ll i = low; i <= high; i++){
    long long area = 1;
    area += i - l[i] - 1;
    
    if(r[i])
      area += r[i] - i - 1;
    
    else
      area += high - i;
    
    area *= v[i];
    ans = max(ans, area);
  }

  return ans;
}

int main(){
  fastio;
  cin >> n;
  v.resize(n+1);

  for(ll i = 1; i <= n; i++)
    cin >> v[i];

  cin >> q;
  while(q--){
    ll op, a, b;
    cin >> op >> a >> b;

    if(op == 1){
      cout << calc(a, b) << "\n";
    }
    else{
      v[a] = b;
    }
  }
}