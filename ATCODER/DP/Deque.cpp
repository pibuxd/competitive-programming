#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n;
vector<int> a;
vector<vector<int>> d;

signed main(){
  fastio;
  cin >> n;
  a.assign(n+1, 0);
  d.assign(n+2, vector<int>(n+2, 0));

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  if(n == 1){
    cout << a[1];
    return 0;
  }

  for(int k = 0; k <= n; k++){
    for(int i = 1; i+k <= n; i++){
      int j = i+k;

      if((n - (j-i+1)) % 2 == 0)
        d[i][j] = max(d[i+1][j] + a[i], d[i][j-1] + a[j]);
      else
        d[i][j] = min(d[i+1][j] - a[i], d[i][j-1] - a[j]);
    }
  }

  cout << d[1][n];
}