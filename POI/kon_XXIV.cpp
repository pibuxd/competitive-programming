// sqrt algorithm O(n*sqrt(n))
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n, k;
  cin >> n >> k;
  int sq = 316;
  vector<vector<int>> D(sq+2, vector<int>(sq+2));
  vector<int> sum(n+1); 
  vector<vector<array<int, 2>>> x(n+2), y(n+2);

  while(k--){
    int a, l, d; cin >> a >> l >> d;

    if(l <= sq || d >= sq){
      for(int i = 0; i < l; i++)
        sum[a + d*i]++;

    } else{ // l > sq && d < sq
      x[a].push_back({l, d});
      y[a + d*(l-1)].push_back({l, d});
    }
  }

  for(int i = 1; i <= n; i++){
    for(auto [l, d] : x[i])
      D[d][(i-1)%d]++;
    for(int j = 1; j < sq; j++)
      sum[i] += D[j][(i-1)%j];
    for(auto [l, d] : y[i])
      D[d][(i-1)%d]--;
  }

  for(int i = 1; i <= n; i++)
    cout << sum[i] << " ";
  cout << "\n";
}
