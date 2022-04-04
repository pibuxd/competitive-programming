// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

int n;
vector<ll> a, _a;

bool check(int x){
  ll curr = a[x];

  for(int i = 1; i <= n; i++){
    if(i == x) continue;

    if(a[i] < curr)
      curr += a[i];
    else
      return false;
  }

  return true;
}

int main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  _a.resize(n+1);

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    _a[i] = a[i];
  }

  sort(a.begin(), a.end());

  int l = 1, r = n, w = 0;
  while(l <= r){
    int m = (l+r)/2;
    if(check(m))
      r = m-1, w = m;
    else
      l = m+1;
  }

  for(int i = 1; i <= n; i++){
    if(_a[i] >= a[w] && w != 0)
      cout << "T";
    else
      cout << "N";
  }
}