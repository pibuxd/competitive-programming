#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n;

vector<vector<int>> solve(){
  vector<vector<int>> mat(n+1, vector<int>(n+1));
  int x = 1;
  int y = n*n;
  bool k = 0;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(k == 0) mat[i][j] = x++;
      else mat[i][j] = y--;
      k = (k == 0 ? 1 : 0);
    }
    if(i % 2 == 0)
      reverse(mat[i].begin()+1, mat[i].end());
  }

  return mat;
}

int main(){
  fastio;
  int t; cin >> t;
  while(t--){
    cin >> n;
    auto s = solve();
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++)
        cout << s[i][j] << " ";
      cout << "\n";
    }
  }
}
