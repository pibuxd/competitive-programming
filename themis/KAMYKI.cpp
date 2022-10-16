#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n;
vector<int> v;

int solve(){
  cin >> n;
  v.assign(n+1, 0);
  
  int X = 0;
  
  for(int i = 1; i <= n; i++){
    int a; cin >> a;
    v[i] = a % 5;
    X ^= v[i];
  }

  if(X != 0) return 0;
  if((X^1) != 0) return 1;
  if((X^2) != 0) return 2;
  if((X^3) != 0) return 3;
  if((X^4) != 0) return 4;
  return -1;
}

int main(){
  fastio;
  int q; cin >> q;
  while(q--) cout << solve() << "\n";
}
