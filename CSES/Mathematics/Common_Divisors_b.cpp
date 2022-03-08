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
    occ[a]++;
  }
 
  for(int g = MX; g >= 1; g--){
    int d = 0;
 
    for(int i = g; i <= MX; i += g)
      d += occ[i];  
 
    if(d >= 2){
      cout << g;
      break;
    }
  }
}