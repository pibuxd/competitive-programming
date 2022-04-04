// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> v(400002);

bool check(int k){
  int l = 1, r = 1;

  int x = 0;
  while(r <= 2*k + 1){
    if(v[r] < k + 1 && r != k + 1)
      x++;
    r++;
  }
  r--;

  while(r <= n){
    if(x == 0 && v[l + k] >= 2*k + 1)
      return true;

    if(r == n) break;

    if(v[l + k] < k + 1)
      x++;
    if(v[l] < k + 1)
      x--;
    if(v[r+1] < k + 1)
      x++;
    if(v[l+1 + k] < k + 1)
      x--;
    l++;
    r++;
  }

  return false;
}

int solve(){
  cin >> n;

  for(int i = 1; i <= n; i++)
    cin >> v[i];
  
  int l, r, ans;
  l = 1, r = n+1, ans = 0;

  while(l <= r){
    int m = (l+r)/2;

    if(check(m))
      ans = m, l = m + 1;
    else  
      r = m - 1;
  }

  return ans;
}

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--)
    cout << solve() << "\n";
}