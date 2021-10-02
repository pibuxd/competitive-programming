#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n;
  cin >> n;
  
  long long x = 0, ans = 0;

  while(n--){
    long long s;
    cin >> s;
    if(s) ans += x;
    else x++;
  }

  cout << ans;
}