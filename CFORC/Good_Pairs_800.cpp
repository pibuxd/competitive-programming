// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> a(n+1);

    int m1 = 0, m2 = 0, m1i = 0, m2i = 0;
    for(int i = 1; i <= n; i++){
      int x; cin >> x;
      if(x > m1){
        m1 = x, m1i = i;
      }
      if(x < m2 || m2 == 0){
        m2 = x, m2i = i;
      }
    }

    cout << m1i << " " << m2i << "\n";
  }
}