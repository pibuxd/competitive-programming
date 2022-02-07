#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF 1e7

int n, m, k, l, LOGM;
vector<vector<int>> a;
vector<vector<vector<int>>> sparse;

void build(){ // O(n * (m * log2(m)))
  for(int y = 1; y <= n; y++)
    for(int j = 1; j <= LOGM; j++)
      for(int i = 1; i + (1 << (j-1)) <= m; i++)
        sparse[y][i][j] = min(sparse[y][i][j-1], sparse[y][i+(1<<(j-1))][j-1]);
}

int query(int y, int a, int b){ // O(1)
  int len = b - a + 1;
  int j = floor(log2(len));
  return min(sparse[y][a][j], sparse[y][b-(1<<j)+1][j]);
}

int getmin(int y, int x){ // O(n)
  int mn = INF;

  for(int i = y; i <= y+k-1; i++)
    mn = min(mn, query(i, x, x+l-1));

  return mn;
}

int main(){
  fastio;
  cin >> n >> m >> k >> l;

  LOGM = ceil(log2(m));
  a.resize(n+1, vector<int>(m+1));
  sparse.resize(n+1, vector<vector<int>>(m+1, vector<int>(LOGM+1)));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
      sparse[i][j][0] = a[i][j];
    }
  }

  build();

  for(int i = 1; i <= n-k+1; i++){
    for(int j = 1; j <= m-l+1; j++)
      cout << getmin(i, j) << " ";
    cout << "\n";
  }
}