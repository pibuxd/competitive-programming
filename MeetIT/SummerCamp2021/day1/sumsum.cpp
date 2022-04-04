// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * NGE (Next Greater Element)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n, ans;
vector<ll> p, l_high, r_high, l_higher, r_higher;

int main(){
  fastio;
  cin >> n;
  p = l_high = l_higher = vector<ll>(n+1);
  p = r_high = r_higher = vector<ll>(n+1, n+1);
  ans = 0;

  for(ll i = 1; i <= n; i++)
    cin >> p[i];

  stack<pair<ll, ll>> S1, S2;
  for(ll i = 1; i <= n; i++){
    while(!S2.empty()){
      if(p[i] > S2.top().first){
        r_higher[S2.top().second] = i;
        S2.pop();
      }
      else break;
    }
    vector<pair<ll, ll>> to_push;
    while(!S1.empty()){
      if(p[i] > S1.top().first){
        r_high[S1.top().second] = i;
        to_push.push_back(S1.top());
        S1.pop();
      }
      else break;
    }
    if(to_push.size() > 0)
      for(ll it = to_push.size()-1; it >= 0; it--)
        S2.push(to_push[it]);

    S1.push({p[i], i});
  }

  S1 = S2 = stack<pair<ll, ll>>();
  for(ll i = n; i >= 1; i--){
    while(!S2.empty()){
      if(p[i] > S2.top().first){
        l_higher[S2.top().second] = i;
        S2.pop();
      }
      else break;
    }
    vector<pair<ll, ll>> to_push;
    while(!S1.empty()){
      if(p[i] > S1.top().first){
        l_high[S1.top().second] = i;
        to_push.push_back(S1.top());
        S1.pop();
      }
      else break;
    }
    if(to_push.size() > 0)
      for(ll it = to_push.size()-1; it >= 0; it--)
        S2.push(to_push[it]);

    S1.push({p[i], i});
  }

  // for(ll i = 1; i <= n; i++)
  //   cout << i << ": L = " << l_high[i] << ", R = " << r_high[i] << 
  //   " ; LL = " << l_higher[i] << ", RR = " << r_higher[i] << "\n";

  for(ll i = 1; i <= n; i++){
    if(l_high[i] != 0){
      ans += p[i] * ((l_high[i]-l_higher[i]) * (r_high[i]-i));
    }
    if(r_high[i] != n+1){
      ans += p[i] * ((r_higher[i]-r_high[i]) * (i-l_high[i]));
    }
  }

  cout << ans;
}
// 12
// 7 5 8 11 6 9 2 3 12 1 4 10