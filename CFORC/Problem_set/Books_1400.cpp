// * 2P (Two poiners)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, t;
vector<int> v;

int get_seg(int &i){
  while(i < n && v[i] > t){
    i++;
  }
  if(i == n)
    return 0;

  int f, ans, _t, res;
  ans = 1, f = i, _t = v[i], res = 1;
  i++;

  while(i < n && f < n){
    if(_t + v[i] <= t){
      _t += v[i];
      ans++;
      res = max(ans, res);
      i++;
    }
    else{
      _t -= v[f];
      f++;
      ans--;
    }
  }
  return res;
}

int main(){
  fastio;
  cin >> n >> t;
  v.resize(n);

  for(int &x : v) cin >> x;

  int ans = -1;

  for(int i = 0; i < n; i++){
    int _ans = get_seg(i);
    ans = max(ans, _ans);
  }

  cout << ans;
}