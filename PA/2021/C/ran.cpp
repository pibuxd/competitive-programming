// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define dlg (r-l+1)

// struct hash_pair {
//   ll operator() (const pair<ll, ll> &p) const{
//     auto h1 = hash<ll>{}(p.first);
//     auto h2 = hash<ll>{}(p.second);
//     return h1 ^ h2;
//   }
// };

int n, spos;
vector<int> a;
set<pair<int, int>> s;

void foo(int l, int r, bool parz, int med, int mx_excl){
  if(!parz)
    med++;

  if(s.count({l, r}))
    return;
  s.insert({l, r});

  if(mx_excl < med)
    spos++;
  if(l == r)
    return;

  if(a[l] < med){
    foo(l+1, r, !parz, med, max(mx_excl, a[l]));
  }
  if(a[r] < med){
    foo(l, r-1, !parz, med, max(mx_excl, a[r]));
  }

  if(a[l] >= med && a[r] >= med){
    if(a[l] < a[r]){
      foo(l+1, r, !parz, med, max(mx_excl, a[l]));

    } else{
      foo(l, r-1, !parz, med, max(mx_excl, a[r]));
    }
  }
}

int main(){
  fastio;
  cin >> n;
  cout << (2*n + 1) << " ";
  a.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  spos = 0;
  foo(1, n, !(n&1), n/2, 0);

  cout << spos << "\n";
}