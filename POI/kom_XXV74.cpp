#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int INF = 1e9, mxn = 1e7;
vector<int> d, pref;

int sumdziel(int x){
  int res = 1;
  pair<int, int> last = {0, 0};
  while(x > 1){
    if(last.first == d[x]) last.second++;
    else{
      res *= last.second+1;
      last = {d[x], 1};
    }
    x /= d[x];
  }
  res *= last.second+1;

  return res;
}

void prepref(int n){
  pref.resize(n+1, 0);
  vector<int> kol = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
  int sumcyfr = 0, it = 0;
  for(int i = 1; i <= n; i++){
    if(i == kol[it]) sumcyfr++, it++;
    pref[i] = pref[i-1] + (sumdziel(i) == sumcyfr ? 1 : 0);
  }
}

int sum(int _l, int _r){
  return pref[_r] - pref[_l-1];
}

void sito(int n){
  d.resize(n+1, INF);

  for(int i = 2; i*i <= n; i++){
    if(d[i] != INF) continue;
    else d[i] = i;
    for(int j = i*i; j <= n; j += i)
      d[j] = min(d[i], d[j]);
  }
}

signed main(){
  fastio;
  sito(mxn);
  prepref(mxn);

  //for(int i = 1; i <= 150; i++) cout << i << ": " << d[i] << "\n";
  //for(auto i : getfac(22000)) cout << i.first << ": " << i.second << "\n";

  int t; cin >> t;
  while(t--){
    int a, b; cin >> a >> b;
    cout << sum(a, b) << "\n";
  }
}

