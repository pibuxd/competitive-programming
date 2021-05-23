#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;

auto solve(vector<int> &p){
  vector<vector<int>> pier(n+1, vector<int>(n+1)), drug(n+1, vector<int>(n+1));

  for(auto d = 1; d <= n-1; d++)
    for(auto i = 0; i <= n-1; i++){
      auto j = (i + d) % n;
      pier[i][j] = max(p[i] + drug[i+1][j], p[j] + drug[i][j-1]);
      drug[i][j] = min(pier[i+1][j], pier[i][j-1]);
    }

  auto maxi = 0;
  for(auto i = 0; i < n; i++){
    for(auto j = 1; j < n; j++)
      maxi = max(maxi, drug[i+1][j]+p[i]);
  }

  auto sum2 = 0;

  for(auto x : p){
    sum2 += x;
  }

  auto ans = make_pair(maxi, sum2 - maxi);
  return ans;
}

int main(){ fastio;
  int t;
  cin >> t;

  while(t--){
    cin >> n;

    vector<int> p(n); // pizza
    for(auto &x : p) cin >> x;
    
    auto ans = solve(p);
    cout << ans.first << " " << ans.second << "\n";
  }
}