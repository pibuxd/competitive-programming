#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF 1e7

int n, m, k, l;
vector<vector<int>> a;

int getmin(int y, int x){
  int mn = INF;
  for(int i = y; i < y+k; i++){
    for(int j = x; j < x+l; j++){
      mn = min(mn, a[i][j]);
    }
  }
  return mn;
}

int main(){
  fastio;
  cin >> n >> m >> k >> l;

  a.resize(n+1, vector<int>(m+1));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
    }
  }

  for(int i = 1; i <= n-k+1; i++){
    for(int j = 1; j <= m-l+1; j++){
      cout << getmin(i, j) << " ";
    }

    cout << "\n";
  }
}