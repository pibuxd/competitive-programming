#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
  int a, b, ans = 0;
  cin >> a >> b;

  while(a != 0 || b != 0){
    ans += b-a;
    b /= 10;
    a /= 10;
  }

  cout << ans << "\n";
  
  }
}