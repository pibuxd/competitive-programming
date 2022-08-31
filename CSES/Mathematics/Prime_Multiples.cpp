// inclusion-exclusion principle
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n, k, ans;
vector<int> kv;

void foo(int sum, int siz, int ki){
  if(ki > k || sum > n/kv[ki]) return;
  
  int SUM = sum * kv[ki];
  int SIZ = siz + 1;
  int KI = ki + 1;
  if(SIZ % 2 == 1){
    ans += n / SUM;
  } else{
    ans -= n / SUM;
  }
  foo(SUM, SIZ, KI);
  foo(sum, siz, ki+1);
}

signed main(){
  fastio;
  cin >> n >> k;

  kv.assign(k+1, 0);

  for(int i = 1; i <= k; i++)
    cin >> kv[i];

  sort(all(kv));
  ans = 0;
  foo(1, 0, 1);
  
  cout << ans << "\n";
}
