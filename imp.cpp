#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

const ll MOD = 1000000007;
ll n;
vector<ll> h, a, vis;

ll silnia(ll x){
  ll res = 1;
  for(int i = 2; i <= x; i++)
    res = (res * i) % MOD;
  return res;
}

ll solve(){
  if(n == 2){
    if(h[1] != h[2]) return 1;
    else return 0;
  }
  else if(n == 3){
    if(h[1] == h[3]) return 2;
    else return 0;
  }


  a.resize(n+1);
  vis.resize(n+1);

  a[2] = h[1];
  a[n-1] = h[n];

  vis[h[1]] = 1, vis[h[2]] = 2;

  for(int i = 3; i <= n; i++){
    if(!vis[h[i]]){
      vis[h[i]] = i;
    }
    else{
      if(vis[h[i]] != i-2)
        return 0;
      else
        a[i-1] = h[i];
    }
  }
  
  for(int i = 2; i <= n-1; i++){ // jesli jedno juz wiadome (od przodu)
    if(a[i-1] && !a[i+1] && h[i] != a[i-1])
      a[i+1] = h[i];
    else if(!a[i-1] && a[i+1] && h[i] != a[i+1])
      a[i-1] = h[i];
  }

  for(int i = n-1; i >= 2; i--){ // jesli jedno juz wiadome (od tylu)
    if(a[i-1] && !a[i+1] && h[i] != a[i-1])
      a[i+1] = h[i];
    else if(!a[i-1] && a[i+1] && h[i] != a[i+1])
      a[i-1] = h[i];
  }

  a[2] = h[1];
  a[n-1] = h[n];
  for(int i = 2; i <= n; i++){ // sprawdzenie
    if(a[i] != h[i-1] && a[i] != h[i+1] && a[i] != 0) return 0;
    if(a[i-1] != 0 && a[i+1] != 0 && h[i] != a[i-1] && h[i] != a[i+1]) return 0;
  }

  ll nie_wiadomo = 0;
  for(int i = 1; i <= n; i++)
    if(vis[i] == 0)
      nie_wiadomo++;

  ll sil = silnia(nie_wiadomo);
  ll ans = 1;

  ll dlg = 0;
  for(int i = 1; i <= n; i += 2){
    if(a[i]){
      if(dlg > 0)
        ans = (ans * dlg) % MOD;
      dlg = 0;
    }
    else{
      dlg++;
    }
  }
  if(dlg > 0)
    ans = (ans * dlg) % MOD;

  dlg = 0;
  for(int i = 2; i <= n; i += 2){
    if(a[i]){
      if(dlg > 0)
        ans = (ans * dlg) % MOD;
      dlg = 0;
    }
    else{
      dlg++;
    }
  }
  if(dlg > 0)
    ans = (ans * dlg) % MOD;

  // for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
  // cout << "SIL = " << sil << "\n";

  ans = (ans * sil) % MOD;
  return ans;
}

int main(){
  fastio;
  cin >> n;
  h.resize(n+1);
  
  for(int i = 1; i <= n; i++)
    cin >> h[i];

  cout << solve();
}