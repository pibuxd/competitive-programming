#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MX (int)(1e6)

int main(){
  fastio;
  int n; cin >> n;

  vector<int> occ(MX+1);
  for(int i = 1; i <= n; i++){
    int a; cin >> a;
    
    for(int d = 1; d*d <= a; d++){
      if(a % d == 0){
        occ[d]++;
        if(d != a/d)
          occ[a/d]++;
      }
    }
  }

  for(int i = MX; i >= 1; i--)
    if(occ[i] >= 2){
      cout << i;
      break;
    }
}