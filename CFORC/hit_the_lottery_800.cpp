// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n;
  cin >> n;
  int ans = 0;
  int bills[5] = {1, 5, 10, 20, 100};
  int i = 4;

  while(n > 0){
    int temp = n / bills[i];
    ans += temp;
    n -= bills[i] * temp;
    i--;
  }

  cout << ans;
}