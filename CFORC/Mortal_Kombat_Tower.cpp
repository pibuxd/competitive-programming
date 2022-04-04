// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    int ans = a[0] == 1;

    for(int i = 1; i < n; i++){
      if(!a[i]) continue;

      int j = i;
      while(j < n && a[j]){
        j++;
      }

      ans += (j - i) / 3;
      i = j - 1; 
    }

    cout << ans << "\n";
  }
}

// 0 1 0 0 0 1 1 1 1