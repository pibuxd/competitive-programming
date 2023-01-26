#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, t, k;
int *x, *pref, *zl, *zr;

int ilepot(int l, int r){
  return (r-l+1)*k - pref[r] + pref[l-1];
}

int solve(){
  for(int i = 1; i <= n; i++)
    zl[i] = max(zl[i-1] - k + x[i], (int)0);
  for(int i = n; i >= 1; i--)
    zr[i] = max(zr[i+1] - k + x[i], (int)0);

  int l = 1, r = 1;
  while(r <= n){
    if(ilepot(l, r) <= zl[l-1] + zr[r+1]) r++;
    else l++, r++;
  }
  return r-l;
}

signed main(){
  fastio;
  cin >> n >> t;
  x = new int[n+1];
  pref = new int[n+1];
  zl = new int[n+1];
  zr = new int[n+2];
  
  for(int i = 1; i <= n; i++)
    cin >> x[i];
  for(int i = 1; i <= n; i++)
    pref[i] = pref[i-1] + x[i];
  while(t--){
    cin >> k;
    cout << solve() << " ";
  }
}
