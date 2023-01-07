// this is solution using 2d prefix sums
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<vector<int>> a, pref;

void creatematrix(int s){
  pref.assign(n+1, vector<int>(m+1, 0));
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + (a[i][j] >= s ? 1 : 0);
}

int sum(int x1, int y1, int s){
  int x2 = x1+s-1, y2 = y1+s-1;
  return pref[x2][y2] - pref[x2][y1-1] - pref[x1-1][y2] + pref[x1-1][y1-1];
}

bool check(int l){
  creatematrix(l);
  for(int i = 1; i <= n-l+1; i++)
    for(int j = 1; j <= m-l+1; j++)
      if(sum(i, j, l) == l*l)
        return true;
  return false;
}

int solve(){
  int l = 1, r = min(n, m), res = 1;
  while(l <= r){
    int mid = (l+r)/2;
    if(check(mid))
      l = mid+1, res = mid;
    else
      r = mid-1;
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
    cout << solve() << "\n";
  }
}
