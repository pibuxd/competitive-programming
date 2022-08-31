#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()


void solve(){
  int n, m;
  cin >> n >> m;
  
  bool istree = false;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      char c; cin >> c;
      if(c == '^') istree = true;
    }
  }

  if((n == 1 || m == 1) && istree){
    cout << "Impossible\n";
    return;
  }
  cout << "Possible\n";
  
  char a = '^';
  if(!istree) a = '.';
  
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cout << a;
    }
    cout << "\n";
  }
}

int main(){
  fastio;
  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }


}
