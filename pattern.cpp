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
    while(!S1.empty()){
      if(p[i] > S1.top().first){
        r_high[S1.top().second] = i;
        S2.push(S1.top());
        S1.pop();
      }
      else break;
    }

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
    while(!S1.empty()){
      if(p[i] > S1.top().first){
        l_high[S1.top().second] = i;
        S2.push(S1.top());
        S1.pop();
      }
      else break;
    }

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
// 5 3 4 3 2 1 2 1 2 3 3 6