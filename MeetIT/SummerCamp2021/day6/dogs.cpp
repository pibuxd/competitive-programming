#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

const int INF = LONG_MAX;
int n, m, q;
int d1, d2, d3;
vector<int> c;
vector<vector<ll>> dist; 
vector<vector<vector<vector<int>>>> dp;

void floyd_warshall(){
  for(int i = 1; i <= n; i++)
    dist[i][i] = 0;
  
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++){
        if(dist[i][j] > dist[i][k] + dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
}

int main(){
  fastio;
  cin >> n >> m;
  cin >> d1 >> d2 >> d3;
  c.resize(n+1);
  dist.resize(n+1, vector<ll>(n+1, INF));
  dp.resize(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(n+1))));

  for(int i = 1; i <= m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    dist[a][b] = dist[b][a] = w;
  }
  
  floyd_warshall();

  cin >> q;
  
  for(int i = 1; i <= q; i++)
    cin >> c[i];

  dp[1][d1][d2][d3] = min({dist[d1][c[1]], dist[d2][c[1]], dist[d3][c[1]]});

  for(int x = 2; x <= q; x++){
    for(int y = 1; y <= x; y++){
      for(int z = 1; z <= x; z++){
        dp[x][]
      } 
    }
  }
}