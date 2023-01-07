#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t; cin >> t;
  while(t--){
    int n, k; cin >> n >> k;
    int a = n, b = 1;
    for(int i = 1; i <= n; i++){
      if(i % 2 == 1) cout << a-- << " ";
      else cout << b++ << " ";
    }
    cout << "\n";
  }
}
