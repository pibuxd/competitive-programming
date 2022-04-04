// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, sum;
vector<int> a;

int nextPow(int x){
  // x--;
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  x++;
  return x;
}

signed main(){
  fastio;
  cin >> n;

  a.resize(n);
  unordered_map<int, int> M;

  for(int i = 0; i < n; i++){
    cin >> a[i];
    M[a[i]]++;
  }

  sort(a.rbegin(), a.rend());
  sum = 0;

  for(int x : a){
    int np = nextPow(x);
    if(M[np-x] > 0 && M[x] > 0 && (np-x != x || M[x] + M[np-x] > 2)){
      sum++;
      M[x]--;
      M[np-x]--;
      // cout << np << " = " << x << ", " << np-x << "\n";
    }
  }

  cout << sum;
}