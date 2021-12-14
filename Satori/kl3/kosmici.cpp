#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define INF INT_MAX
#define mxn 10001

struct Kosmita {
  int a = 0, b = 0, d = 0;

 bool operator < (const Kosmita &X){
   return b < X.b;
 }
};

int n;
vector<Kosmita> v;

int main(){
  fastio;
  // cout << "\n";
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    v.assign(n+1, Kosmita());
    for(int i = 1; i <= n; i++)
      cin >> v[i].a >> v[i].b >> v[i].d;
    
    sort(all(v));
    // for(int i = 1; i <= n; i++) cout << v[i].a << " " << v[i].b << " " << v[i].d << "\n";

    vector<vector<array<int, 4>>> dp(n+1, vector<array<int, 4>>(mxn+1, {INF, INF, INF, INF})); // ans, b, d, old

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= mxn; j++){
          if(v[i].d > j) continue;
          if(dp[i-1][mxn][0] == INF){
            dp[i][j] = {v[i].d, v[i].b, v[i].d, 0};
            continue;
          }

          if(v[i].a <= dp[i-1][mxn][1]){ // mozna polaczyc z ciagiem poprzedniego
            if(v[i].d > dp[i-1][mxn][2]){ // trzeba zwiekszyc moc
              dp[i][j] = {dp[i-1][mxn][0] - dp[i-1][mxn][2] + v[i].d, dp[i-1][mxn][1], v[i].d, dp[i-1][mxn][0]};

            } else{ // nie trzeba zwiekszyc mocy
              dp[i][j] = dp[i-1][mxn];
            }

          } else{ // nie da sie dolepic
            if(dp[i])
            dp[i][j] = {dp[i-1][mxn][3] + v[i].d, v[i].b, v[i].d, dp[i-1][mxn][0]};
          }
            
      }
    }

    for(int i = 1; i <= n; i++){
      // for(int j = 1; j <= 20; j++){
        cout << dp[i][20][0] << " , " << dp[i][20][3] << " ";
      // }
      cout << "\n";
    }
    cout << dp[n][mxn][0] << "\n";
  }
}