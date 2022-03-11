// * calculate ( i->n ∑ σ(i) ) modulo 10^9+7 in O(sqrt(n))
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define M (int)(1e9+7)

int sum(int x){
  return (((x)*(x+1))/2)%M;
}

void add(int &a, int b){
  a = (a+b+M)%M;
}

signed main(){
  fastio;
  int n; cin >> n;

  int ans = 0;

  for(int i = 1; i*i <= n; i++){
    int ile = (n/i)%M;
    int _ile = (ile-i+1)%M;
    
    add(ans, (_ile*i)%M);
    add(ans, (sum(ile)-sum(i-1)+M)%M);

    if(ile >= i)
      add(ans, -i);
  }

  cout << ans;
}