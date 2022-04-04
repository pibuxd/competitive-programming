// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<vector<int>> a, pref_11, pref_1m, pref_n1, pref_nm;

void prefix(){ // ok
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      pref_11[i][j] = pref_11[i-1][j] + pref_11[i][j-1] - pref_11[i-1][j-1] + a[i][j];

  for(int i = 1; i <= n; i++)
    for(int j = m; j >= 1; j--)
      pref_1m[i][j] = pref_1m[i-1][j] + pref_1m[i][j+1] - pref_1m[i-1][j+1] + a[i][j];

  for(int i = n; i >= 1; i--)
    for(int j = 1; j <= m; j++)
      pref_n1[i][j] = pref_n1[i+1][j] + pref_n1[i][j-1] - pref_n1[i+1][j-1] + a[i][j];

  for(int i = n; i >= 1; i--)
    for(int j = m; j >= 1; j--)
      pref_nm[i][j] = pref_nm[i+1][j] + pref_nm[i][j+1] - pref_nm[i+1][j+1] + a[i][j];
}

int ile_x(int i, int j, int bok){ // ok
  pair<int, int> A, B, C, D;
  A = {i, j}, B = {i, j+bok-1}, C = {i+bok-1, j+bok-1}, D = {i+bok-1, j};

  return ( pref_11[n][m]
    - pref_11[n][A.second - 1]
    - pref_11[A.first - 1][m]
    - pref_nm[C.first + 1][1]
    - pref_nm[1][C.second + 1]
    + pref_11[A.first - 1][A.second - 1]
    + pref_1m[B.first - 1][B.second + 1]
    + pref_nm[C.first + 1][C.second + 1]
    + pref_n1[D.first + 1][D.second - 1]
  );
}

int check(int bok){ // ok
  int res = 0;

  for(int i = 1; i+bok-1 <= n; i++){
    for(int j = 1; j+bok-1 <= m; j++){
      if(ile_x(i, j, bok) == 0){
        // cout << i << " ; " << j << "\n"; 
        res++;
      }
    }
  }

  return res;
}

auto solve(){
  pair<int, int> res;
  prefix();
  // cout << ile_x(1, 2, 3) << '\n';
  // cout << check(1) << "\n\n";

  int l = 1, r = min(n, m);
  while(l <= r){
    int mid = (l+r)/2;
    int spos = check(mid);

    if(spos > 0)
      l = mid + 1, res = {mid, spos};
    else
      r = mid - 1;
  }

  return res;
}

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    cin >> n >> m;
    a = pref_11 = pref_1m = pref_n1 = pref_nm = vector<vector<int>>(n+2, vector<int>(m+2));

    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++){
        char c; cin >> c;
        if(c == 'x') a[i][j] = 1;
      }
    auto ans = solve();
    cout << ans.first << " " << ans.second << "\n";
  }
}