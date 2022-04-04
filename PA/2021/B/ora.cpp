// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k, ile;
long long ans;
vector<int> a, occ;

int main(){
  fastio;
  cin >> n >> k;
  a.resize(n+1, 0);
  occ.resize(n+1, 0);
  ile = 0;
  ans = 0;

  int x = 0;
  vector<int> to_erase, to_push;
  for(int i = 1; i <= n; i++){
    cin >> a[i], occ[a[i]]++;
    if(occ[a[i]] == 1)
      ile++;
    if(i <= k && occ[a[i]] > 1){
      to_erase.push_back(i);
      x++;
    }
    else if(i > k && occ[a[i]] == 1 && x > 0){
      to_push.push_back(i);
      x--;
    }
  }

  if(ile < k){
    cout << "-1";
    return 0;
  }

  reverse(to_erase.begin(), to_erase.end());
  int _x = 0;
  for(int v : to_erase){
    ans += k - v - _x;
    _x++;
  }
  for(int v : to_push){
    ans += v - (k+1) + _x;
    _x--;
  }

  cout << ans;
}