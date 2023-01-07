#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mxn = 1e7;
vector<int> minpr;

void sieve(){
  minpr.resize(mxn+1);
  for(int i = 1; i <= mxn; i++) minpr[i] = i;

  for(int i = 2; i*i <= mxn; i++){
    if(!minpr[i]) continue;
    for(int j = i*i; j <= mxn; j += i)
      minpr[j] = min(minpr[j], i);
  }
}

vector<int> primes(int x){
  vector<int> res({minpr[x]});
  while(x > 1){
    if(res.back() != minpr[x])
      res.push_back(minpr[x]);
    x /= minpr[x];
  }
  return res;
}

int k(int x, int p){
  if(x%p == 0) return 0;
  int l = x/p;
  return (l+1)*p - x;
}

int solve(int x, int y){
  int r = y-x;
  if(r == 1) return -1;
  int mnk = 1e7+1;
  for(int p : primes(r)){
    int k1 = k(x, p), k2 = k(y, p);
    if(k1 == k2 && mnk > k1)
      mnk = k1;
  }
  return mnk;
}

int main(){
  fastio;
  int t; cin >> t;
  sieve();

  while(t--){
    int x, y; cin >> x >> y;
    cout << solve(x, y) << "\n";
  }
}
