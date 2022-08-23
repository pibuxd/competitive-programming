#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

signed main(){
  fastio;
  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    int A, B; cin >> A >> B;
    int mnop = INT_MAX;
    int addedB = 0;
    while(true){
      if(B <= 1){
        B++, addedB++;
        continue;
      }
      int op = floor(log(A)/log(B)) + addedB + 1;
      B++, addedB++;
      if(op < mnop) mnop = op;
      else break;
    } 
    
    cout << mnop << "\n";
  }
}