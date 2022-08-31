#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, m, k, ans;
vector<vector<int>> a;
vector<vector<unordered_map<int, int>>> s;

void foo(int sum, int i, int j){
  if(m-j+1 == i){
    s[i][j][sum]++;
    return;
  }
  if(1 <= i+1 && i+1 <= n)
    foo(sum ^ a[i+1][j], i+1, j);
  if(1 <= j+1 && j+1 <= m)
    foo(sum ^ a[i][j+1], i, j+1);
}

void FOO(int sum, int i, int j){
  if(m-j+1 == i){
    ans += s[i][j][sum^a[i][j]^k];
    return;
  }
  if(1 <= i-1 && i-1 <= n)
    FOO(sum ^ a[i-1][j], i-1, j);
  if(1 <= j-1 && j-1 <= m)
    FOO(sum ^ a[i][j-1], i, j-1);
}

signed main(){
  fastio;
  cin >> n >> m >> k;

  a.resize(n+1, vector<int>(m+1));
  s.resize(n+1, vector<unordered_map<int, int>>(m+1));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
    }
  }

  foo(a[1][1], 1, 1);
  ans = 0;
  FOO(a[n][m], n, m);

  cout << ans << "\n";
}
