#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, k;
vector<int> dp, a;

int main(){
  fastio;
  cin >> k;
  a.resize(k+1);

  for(int i = 1; i <= k; i++)
    cin >> a[i];
  sort(all(a));

  dp.assign(1000+1, 2);

  for(int i = 1; i <= 1000; i++){
    for(int j = 1; j <= k; j++){
      if(i-a[j] < 0) break; // break, bo a[j] jest rosnace, bo posortowalem

      if(dp[i-a[j]] == 2) dp[i] = 1;
    }
  }

  cin >> n;
  for(int i = 1; i <= n; i++){
    int x; cin >> x;
    cout << (dp[x] == 1 ? "AGATA" : "JULEK") << "\n";
  }
}
