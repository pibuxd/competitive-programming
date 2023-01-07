// this is solution using 2d sparse table
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, INF = 1e6+1;
vector<vector<int>> a;
vector<vector<vector<int>>> sp;

void precalc(){
  int LG = log2(min(n, m));
  sp.assign(LG+1, vector<vector<int>>(n+1, vector<int>(m+1, INF)));
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= m; j++)
      sp[0][i][j] = a[i][j];

  for(int l = 1; l <= LG; l++)
    for(int i = 1; i+(1<<(l-1)) <= n; i++)
      for(int j = 1; j+(1<<(l-1)) <= m; j++)
        sp[l][i][j] = min({sp[l-1][i][j], sp[l-1][i+(1<<(l-1))][j], sp[l-1][i][j+(1<<(l-1))], sp[l-1][i+(1<<(l-1))][j+(1<<(l-1))]});
}

int mn(int x, int y, int l, int d){
  return min({sp[d][x][y], sp[d][x][y+l-(1<<d)], sp[d][x+l-(1<<d)][y], sp[d][x+l-(1<<d)][y+l-(1<<d)]});
}

bool check(int l){
  int d = log2(l);
  for(int i = 1; i <= n-l+1; i++)
    for(int j = 1; j <= m-l+1; j++)
      if(mn(i, j, l, d) >= l)
        return true;
  return false;
}

int solve(){
  int l = 1, r = min(n, m), res = 1;
  while(l <= r){
    int mid = (l+r)/2;
    if(check(mid)) l = mid+1, res = mid;
    else r = mid-1;
  }
  return res;
}

int main(){
  fastio;
  int t; cin >> t;
  while(t--){
    cin >> n >> m;
    a.assign(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        cin >> a[i][j];
    precalc();
    cout << solve() << "\n";
  }
}
