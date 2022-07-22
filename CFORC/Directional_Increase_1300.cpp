#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long 

signed main(){
  fastio;
  int t; cin >> t;
  while(t--){
    int n; cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }

    int sum = 0;
    bool added = false;
    for(int i = n; i >= 2; i--){
      if(a[i] != 0) added = true;
      sum += a[i];
      if(sum >= 0 && added){
        cout << "No\n";
        goto end;
      }
    }
    sum += a[1];
    if(sum == 0) cout << "Yes\n";
    else cout << "No\n";
    
    end:;
  }
}