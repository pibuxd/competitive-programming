#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
//#define int long long
#define int unsigned int

int INF = 1e9, mxn = (1e8)/6;
vector<int> pr, pref, v, V9;

void prepref(int n){
  pref.resize(n+1, 0);
  for(int i = 1; i <= n; i++)
    pref[i] = pref[i-1] + v[i];
}

int sum(int _l, int _r){
  int L = lower_bound(all(V9), _l-1)-v.begin();
  int R = lower_bound(all(V9), _r)-v.begin();
  _r = min(_r, mxn);
  return pref[_r] - pref[_l-1] + R-L;
}

void sito(int n){
  vector<bool> ispr(n+1, true);
  for(int i = 2; i*i <= n; i++){
    if(!ispr[i]) continue;
    for(int j = i*i; j <= n; j += i)
      ispr[j] = false;
  }
  for(int i = 2; i <= n; i++)
    if(ispr[i])
      pr.push_back(i);
}

int pot(int x, int p){
  int res = 1;
  while(p--){
    if(res >= INT_MAX/x) return INF;
    res *= x;
  }
  return res;
}

void foo(int num, int itpr, int itw, const vector<int> &w, int dlim, int lim){
  if(num > lim) return;
  if(itw == w.size()){
    if(num < dlim) return;
    if(num <= mxn)
      v[num] = 1;
    else
      V9.push_back(num);
    return;
  }
  if(itpr == pr.size()) return;

  if(num <= lim/pot(pr[itpr+1], w[itw]))
    foo(num, itpr+1, itw, w, dlim, lim);
  if(num <= lim/pot(pr[itpr], w[itw]))
    foo(num*pot(pr[itpr], w[itw]), itpr+1, itw+1, w, dlim, lim);
}

signed main(){
  fastio;
  sito(mxn);
  v.resize(mxn+1, 0);
  v[1] = 1;
  vector<tuple<vector<int>, int, int>> H = {
    {{1}, 10, 99},
    {{2}, 100, 999},
    {{3}, 1000, 9999},
    {{1, 1}, 1000, 9999},
    {{4}, 10000, 99999},
    {{5}, 100000, 999999},
    {{1, 2}, 100000, 999999},
    {{2, 1}, 100000, 999999},
    {{6}, 1000000, 9999999},
    {{7}, 10000000, 99999999},
    {{1, 1, 1}, 10000000, 99999999}/*,
    {{2, 3}, 10000000, 99999999},
    {{3, 2}, 10000000, 99999999},
    {{8}, 100000000, 999999999},
    {{2, 2}, 100000000, 999999999}*/
  };

  for(auto h : H)
    foo(1, 0, 0, get<0>(h), get<1>(h), get<2>(h));
  
  prepref(mxn);

  int t; cin >> t;
  while(t--){
    int a, b; cin >> a >> b;
    cout << sum(a, b) << "\n";
  }
}
