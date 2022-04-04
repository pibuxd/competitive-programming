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

    vector<string> v(n);
    for(int i = 1; i <= n-2; i++)
      cin >> v[i];

    string ans = "";
    ans += v[1];
    bool ad = false;
    for(int i = 2; i <= n-2; i++){
      if(v[i][0] == ans.back())
        ans += v[i][1];
      if(v[i][0] != v[i-1][1]){
        ans += v[i][0];
        ans += v[i][1];
        ad = true;
        // cout << i << " ";
      }
    }
    if(!ad)
      ans += 'a';

    cout << ans << "\n";
  }
}