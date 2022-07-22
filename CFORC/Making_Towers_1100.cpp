#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> high(n+1), last(n+1);

    for(int i = 1; i <= n; i++){
      int c; cin >> c;
      if(!last[c] || (i-last[c])%2) high[c]++, last[c] = i;
    }

    for(int i = 1; i <= n; i++) cout << high[i] << " ";
    cout << "\n";
  }
}
