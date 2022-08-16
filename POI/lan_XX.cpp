#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, k;
vector<int> l, c, a;

int gasienica(){
  int len = 0;
  for(int i = 1; i <= n; i++) len += l[i];

  if(len > n) return 0;

  vector<int> currl(n+1, 0);
  for(int i = 1; i <= len; i++)
    currl[a[i]]++;
  int zaduzo = 0, zamalo = 0, ok = 0;

  for(int i = 1; i <= n; i++){
    if(l[i] == currl[i]) ok++;
    else if(l[i] > currl[i]) zamalo++; 
    else if(l[i] < currl[i]) zaduzo++; 
  }

  int res = 0;
  if(ok == n) res++;

  int b = 2, e = len+1;
  while(e <= n){
    if(l[a[b-1]] == currl[a[b-1]]) ok--;
    else if(l[a[b-1]] > currl[a[b-1]]) zamalo--; 
    else if(l[a[b-1]] < currl[a[b-1]]) zaduzo--; 
    currl[a[b-1]]--;
    if(l[a[b-1]] == currl[a[b-1]]) ok++;
    else if(l[a[b-1]] > currl[a[b-1]]) zamalo++; 
    else if(l[a[b-1]] < currl[a[b-1]]) zaduzo++; 

    if(l[a[e]] == currl[a[e]]) ok--;
    else if(l[a[e]] > currl[a[e]]) zamalo--; 
    else if(l[a[e]] < currl[a[e]]) zaduzo--; 
    currl[a[e]]++;
    if(l[a[e]] == currl[a[e]]) ok++;
    else if(l[a[e]] > currl[a[e]]) zamalo++; 
    else if(l[a[e]] < currl[a[e]]) zaduzo++; 

    if(ok == n) res++;
    b++, e++;
  }

  return res; 
}

signed main(){
  fastio;
  cin >> n >> k;

  l.assign(n+1, 0);
  c.assign(n+1, 0);
  a.assign(n+1, 0);
  vector<int> _l(n+1, 0);

  for(int i = 1; i <= k; i++) cin >> _l[i];
  for(int i = 1; i <= k; i++) cin >> c[i];
  for(int i = 1; i <= k; i++) l[c[i]] = _l[i];
  for(int i = 1; i <= n; i++) cin >> a[i];
  
  cout << gasienica() << "\n";
}