#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n, M;
vector<ll> silnie, weird_silnie, dzielenie;

void preprocess(){
  silnie[0] = 1;

  for(int i = 1; i <= n; i++)
    silnie[i] = ( silnie[i-1] * i ) % M;

  weird_silnie[0] = weird_silnie[1] = weird_silnie[2] = 1;
  for(int i = 3; i <= n; i++)
    weird_silnie[i] = ( weird_silnie[i-1] * i ) % M;

  dzielenie[1] = 1;
  ll lic = 1;
  for(int i = 2; i <= n; i++)
    dzielenie[i] = ( dzielenie[i-1] * (n-lic) ) % M, lic++;
}

ll weird_silnia(int x){
  return weird_silnie[x];
}

ll silnia(int x){
  return silnie[x];
}

ll dziel(int x){
  return dzielenie[x];
}

ll last_fun(){
  ll ex1 = weird_silnia(n-1);
  ll ex2 = ( ( (n) * (n-1) ) )%M;
  ex2 += ( ( (n-1) * (n-2) ) / 2 )%M;
  ll res = ( ex1 * ex2 ) % M; 
  return res;
}

ll solve(ll _n, ll _M){
  n = _n, M = _M;
  if(n == 2) return 1;

  silnie.resize(n+1);
  weird_silnie.resize(n+1);
  dzielenie.resize(n+1);
  preprocess();
  
  ll ans = 0;
  ll last = last_fun();
  
  for(int k = 1; k <= n; k++){
    ans = ( ans + last )%M;

    ll x1 = 0, x2 = 0;

    x1 = ( ( ( dziel(k) * (k-n) )%M * (n-1) )%M )%M;
    x2 = ( ( ( silnia(n-1) - dziel(k) )%M * (k) )%M * (n-1) )%M;
    ans = ( ans + (x1 + x2)%M )%M;
  }

  ans = ans % M;
  ans = ( ans + M ) % M;
  return ans;
}

int main(){
  fastio;
  cin >> n >> M;
  cout << solve(n, M) << "\n";
}