#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, m;
vector<int> a;

bool check(int k){
  int pot = n-k;
  // bez 
  vector<int> b = a;
  b[pot+1] = m+1;

  sort(all(b));
  vector<int> p(n+1, 0);

  for(int i = 1; i <= n; i++)
    p[i] = p[i-1] + b[i];

  auto it = upper_bound(all(p), m);
  it--;
  int ii = it-p.begin();
  if(ii >= pot+1) return true;
  
  // z
  int _m = m-a[pot+1];
  if(_m < 0) return false;

  it = upper_bound(all(p), _m);
  it--;
  ii = it-p.begin();
  if(ii+1 >= pot) return true;

  //cout << k << " NIG\n";
  return false;
}

int solve(){
  cin >> n >> m;
  a.assign(n+1, 0);
  for(int i = 1; i <= n; i++) cin >> a[i];

  int l = 1, r = n, ans = n+1;
  while(l <= r){
    int mid = (l+r)/2;
    if(check(mid))
      r = mid-1, ans = mid;
    else
      l = mid+1;
  }
  return ans;
}

signed main(){
  fastio;
  int t; cin >> t;
  while(t--) cout << solve() << "\n";
}
