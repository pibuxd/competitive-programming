#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mxv = 1e6;
int n;
vector<int> primes;

void sieve(){ // O(mxv)
  bitset<mxv+1> vis;
  for(int i = 2; i <= mxv; i++){
    if(!vis[i]){
      primes.push_back(i);
      vis[i] = true;
    }
    for(int p : primes){
      if(i * p <= mxv) vis[i * p] = true;
      else break;
      if(i % p == 0) break;
    }
  }
}

vector<int> primesof(int v){ // O(sqrt(v) / log2(v))
  vector<int> res;
  int sqv = sqrt(v);
  for(int p : primes){
    if(p > sqv || v == 1) break;
    if(v % p == 0){
      res.push_back(p);
      while(v % p == 0) v /= p;
    }
  }
  if(v != 1) res.push_back(v);
  return res;
}

vector<int> M;

void foo(int &sum, vector<int> &pv, int pi, int inc, int d){
  if(pi == pv.size()){
    sum += (inc % 2 == 1 ? 1 : -1) * M[d];
    return;
  }
  foo(sum, pv, pi+1, inc, d);
  d *= pv[pi];
  foo(sum, pv, pi+1, inc+1, d);
}

void add(vector<int> &pv, int pi, int d){
  if(pi == pv.size()){
    if(d > 1)
      M[d]++;
    return;
  }
  add(pv, pi+1, d);
  d *= pv[pi];
  add(pv, pi+1, d);
}

signed main(){
  fastio;
  cin >> n;
  sieve();
  vector<vector<int>> ppv(n+1);
  M.resize(mxv+1);

  for(int i = 1; i <= n; i++){
    int v; cin >> v;
    ppv[i] = primesof(v);
    add(ppv[i], 0, 1);
  }
  for(int i = 1; i <= n; i++){
    int sum = 0;
    foo(sum, ppv[i], 0, 0, 1);
    if(sum) sum--;
    cout << sum << " ";
  }
  cout << "\n";
}
