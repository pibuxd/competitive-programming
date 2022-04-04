// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){ fastio;
  int n;
  cin >> n;
  vector<int> a(n+1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  int m;
  cin >> m;
  vector<int> b(m+1);
  for(int i = 1; i <= m; i++) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = 0;
  int i = 1, j = 1;

  while(i <= n && j <= m){
    if(abs(a[i] - b[j]) <= 1){
      i++, j++, ans++;
    } else if(a[i] > b[j]){
      j++;
    } else if(a[i] < b[j]){
      i++;
    }
  }

  cout << ans;
}