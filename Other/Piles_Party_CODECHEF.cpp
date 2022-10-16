#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

string solve(){
  int n;
  cin >> n;
 
  int x = 0;
  for(int i = 1; i <= n; i++){
    int a; cin >> a;

    if(i % 2 == 1)
      x ^= a % 2;
    else
      x ^= a / 2;
  }
  
  if(x == 0)
    return "CHEFINA";
  return "CHEF";
}

int main(){
  fastio;
  int t; cin >> t;
  while(t--) cout << solve() << "\n";
}
