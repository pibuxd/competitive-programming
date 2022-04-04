// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    vector<int> a(8);
    for(int i = 1; i <= 7; i++){
      cin >> a[i];
    }

    cout << a[1] << " " << a[2] << " " << max(a[7] - a[1] - a[2], a[3]) << "\n";
  }
}