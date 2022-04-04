// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n, m;
  cin >> n >> m;
  int a[n+1];

  int mxn = 0, mxp = 0;
  int l_n = 0, r_n = 0, l_p = 0, r_p = 0;

  for(int i = 1, curr = 0; i <= n; i++){
    char c; cin >> c;
    a[i] = (c == 'W') ? 1 : 2;

    curr += a[i];
    if(curr & 1){
      if(mxn < curr)
        mxn = curr, l_n = 1, r_n = i;
    }
    else{
      if(mxp < curr)
        mxp = curr, l_p = 1, r_p = i;
    }
  }

  for(int i = n, curr = 0; i >= 1; i--){
    curr += a[i];
    if(curr & 1){
      if(mxn < curr)
        mxn = curr, l_n = i, r_n = n;
    }
    else{
      if(mxp < curr)
        mxp = curr, l_p = i, r_p = n;
    }
  }

  pair<int, int> v[2*n+1];
  int l = l_n, r = r_n, val = mxn;
  while(l <= r){
    if(val <= 0) break;
    v[val] = {l, r};
    val -= 2;
    if(a[l] == 2)
      l++;
    else if(a[r] == 2)
      r--;
    else
      l++, r--;
  }

  l = l_p, r = r_p, val = mxp;
  while(l <= r){
    if(val <= 0) break;
    v[val] = {l, r};
    val -= 2;
    if(a[l] == 2)
      l++;
    else if(a[r] == 2)
      r--;
    else
      l++, r--;
  }

  while(m--){
    int k; cin >> k;
    if((k & 1 && k > mxn) || (!(k & 1) && k > mxp))
      cout << "NIE\n";
    else
      cout << v[k].first << " " << v[k].second << "\n";
  }
}