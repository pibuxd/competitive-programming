// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Two pointers
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<int> a, b;

int main(){
  fastio;
  cin >> n >> m;
  a.resize(n);
  b.resize(m);

  for(int &x : a) cin >> x;
  for(int &x : b) cin >> x;

  int ans = 0, ai = 0, bi = 0;

  while(ai < n){
    while(bi < m-1 && abs(a[ai] - b[bi]) >= abs(a[ai] - b[bi+1])){
      bi++;
    }
    ans = max(ans, abs(a[ai] - b[bi]));
    ai++;
  }

  cout << ans;
}