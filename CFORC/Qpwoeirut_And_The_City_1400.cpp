#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int e(int i, vector<int> &h){
  if(h[i] <= max(h[i-1], h[i+1]))
    return max(h[i-1], h[i+1]) - h[i] + 1;
  return 0;
}

signed main(){
  fastio;
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> h(n+1);
    
    for(int i = 1; i <= n; i++){
      cin >> h[i];
    }
    
    int s1 = 0;
    for(int i = 2; i < n; i += 2)
      s1 += e(i, h);
    if(n%2 == 0){ 
      vector<int> l(n+4), r(n+4);
      for(int i = 2; i < n; i += 2)
        l[i] = l[i-2] + e(i, h);
      for(int i = n-1; i > 1; i -= 2)
        r[i] = r[i+2] + e(i, h);
      
      int s2 = l[n-2];
      for(int i = n-1; i > 1; i -= 2){
        if(i == 3){
          s2 = min(s2, r[3]);
          continue;
        }
        s2 = min(s2, r[i]+l[i-3]);
      }
      cout << s2 << "\n";
    } else
      cout << s1 << "\n";
  }       
}
