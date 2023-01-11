#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, k, c;
vector<int> f;

vector<int> fac(int x){
  vector<int> res;
  if(x % 2 == 0) res.push_back(2);
  while(x % 2 == 0) x /= 2;
  
  for(int i = 3; i*i <= x; i += 2){
    if(x % i == 0) res.push_back(i);
    while(x % i == 0) x /= i;
  }

  if(x > 1) res.push_back(x);
  return res;
}

void ch(vector<int> &w, int num, int it, int zos){
  if(zos == 0){
    w.push_back(num);
    return;
  }
  if(it == f.size()) return;
  ch(w, num, it+1, zos);
  ch(w, num*f[it], it+1, zos-1);
}

int ok(int x){
  int res = 0;
  for(int zos = 1; zos <= f.size(); zos++){
    vector<int> m;
    ch(m, 1, 0, zos);
    for(int u : m)
      res += (zos % 2 == 1 ? 1 : -1) * (x/u);
  }
  
  return x-res;
}

signed main(){
  fastio;
  cin >> n >> k >> c;
  f = fac(n);
  //for(int i : f) cout << i << " "; cout << "\n";
  int l = 1, r = 1e17, v;

  while(l <= r){
    int mid = (l+r)/2;
    if(ok(mid) >= k)
      v = mid, r = mid-1;
    else
      l = mid+1;
  }
  
  while(c){
    if(__gcd(n, v) == 1){
      cout << v << " ";
      c--;
    }
    v++;
  }

  cout << "\n";
}
