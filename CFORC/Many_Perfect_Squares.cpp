#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n;
vector<int> tab;
vector<unordered_map<int, int>> M;

void foo(int i, int j, int x, int y){ // x < y
  int d = y-x;
  int b = 1;
  while(b*b < d){
    int a = (d/b + b) / 2;
    if(d % b == 0 && d % (2*a-b) == 0){
      int f = a*a - y;
      //cout << x << ":" << y << ", " << a-b << " " << a << "\n";
      if(f >= 0){
        M[i][f]++;
        //cout << x << ":" << y << ", " << a-b << " " << a << " == " << f << ". " <<  M[i][f] << "\n";
      }
    }
    b++;
  }
}

signed main(){
  fastio;
  int t; cin >> t;
  while(t--){
    cin >> n;
    tab.assign(n+1, 0);
    M.assign(n+1, {});
    
    for(int i = 1; i <= n; i++){
      cin >> tab[i];

      for(int j = 1; j < i; j++){
        foo(i, j, tab[j], tab[i]);
      }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
      for(auto m : M[i])
        ans = max(ans, m.second);
    
    cout << ans+1 << "\n";
  }
}
