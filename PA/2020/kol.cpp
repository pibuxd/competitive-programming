#include "bits/stdc++.h"
using namespace std;

int main(){
  int n, m; cin >> n >> m;
  
  vector<bool> Z(n+1), N(n+1);
  int ans = 0;

  for(int i = 0, l, r, k; i < m; i++){
    cin >> l >> r >> k;
    
    if(k == 2){
      while(l <= r){
        if(!N[l] && Z[l])
          ans++;
        N[l] = true;
        l++;
      }
    } else if(k == 1){
      while(l <= r){
        if(N[l] && !Z[l])
          ans++;
        Z[l] = true;
        l++;
      }
    } else{ // k == 3
      while(l <= r){
        if(N[l] && Z[l])
          ans--;
        N[l] = true;
        Z[l] = true;
        l++;
      }
    }
  }
  cout << ans;
}
