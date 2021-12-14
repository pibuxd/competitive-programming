#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n;
vector<ll> p, par, w;
vector<ll> dist;

int main(){
  fastio;
  ll t;
  cin >> t;
  cout << "\n";
  while(t--){
    cin >> n;
    p.assign(n+1, 0);
    par.assign(n+1, 0);
    w.assign(n+1, 0);
    dist.assign(n+1, 0);
    
    ll root = p[1];

    for(ll i = 1; i <= n; i++){
      cin >> par[i];
      if(par[i] == i) 
        root = i;
    }
    for(ll i = 1; i <= n; i++)
      cin >> p[i];
    
    ll curr = 1;

    if(root != p[1]){
      cout << "-1";
      goto end;
    }
    
    for(ll i = 2; i <= n; i++){ // skip root
      if(par[p[i]] != root &&  w[par[p[i]]] == 0){
        cout << "-1";
        goto end;
      }
      w[p[i]] = curr - dist[par[p[i]]];
      dist[p[i]] = curr;
      curr++;
    }

    for(ll i = 1; i <= n; i++){
      cout << w[i] << " ";
    }
    end:
    cout << "\n";
  }
}