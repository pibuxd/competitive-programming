// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include<bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, x; cin >> n >> x;
  long long ans = 0;

  for(int i = 0; i <= n; i++){
    int a; cin >> a;
    ans += a * pow(x, i);
  }

  cout << ans;
}
