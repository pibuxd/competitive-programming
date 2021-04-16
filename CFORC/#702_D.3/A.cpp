#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int dev(int x){
  if(x%2) return (x+1)/2;
  else return x/2;
}

int add(int a, int b){
  int x = max(a, b);
  int y = min(a, b);
  int add = 0;

  while(x > 2*y){
    x = dev(x);
    add++;
  }

  return add;
}

int main(){
  fastio;
  
  int t;
  cin >> t;

  while(t--){
    int n, ans = 0;
    cin >> n;

    int x, y; // 4 2 -> x, y
    cin >> x >> y;
    n -= 2;

    ans += add(x, y);
    //if(add(x, y) > 0) cout << add(x, y) << ": " << x << ',' << y << ' ';

    while(n--){
      x = y;
      cin >> y;
      ans += add(x, y);
      //if(add(x, y) > 0) cout << add(x, y) << ": " << x << ',' << y << ' ';
    }

    cout << ans << "\n";
  }
}