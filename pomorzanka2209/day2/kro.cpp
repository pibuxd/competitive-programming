#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int X, Y, M = 1e9+7;

int w(int a, int b){
  if(a>b) swap(a,b);
  if(b % a == 0) return 1;
  if(a == 0) return 0;
  return w(b % a, a) + 1;
}

void printwyn(int x, int y){
  for(int i = 1; i <= x; i++){
    for(int j = 1; j <= y; j++){
      int wyn = w(i, j);
      cout << wyn << " ";
    }
    cout << "\n";
  }
}

signed main(){
  fastio;
  X = 1000, Y = 1000;
  //printwyn(4, 4);
  //return 0;
  vector<vector<array<int, 2>>> ans(X+1, vector<array<int, 2>>(Y+1, {0, 0}));
  vector<vector<int>> A(X+1, vector<int>(Y+1, 0));

  for(int i = 1; i <= X; i++){
    for(int j = i; j <= Y; j++){
      int wyn = w(i, j);
      A[i][j] = wyn;
      if(j <= X && i <= Y)
        A[j][i] = wyn;
      //cout << "w(" << i << ", " << j << ") = " << wyn << "\n";
    }
  }

  for(int i = 1; i <= X; i++) ans[i][0] = {0, i};
  for(int i = 1; i <= Y; i++) ans[0][i] = {0, i};

  for(int i = 1; i <= X; i++){
    for(int j = 1; j <= Y; j++){
      int mx = max({ans[i-1][j][0], ans[i][j-1][0], A[i][j]});
      int r1 = 0;
      if(ans[i-1][j][0] == mx) r1 += ans[i-1][j][1];
      if(ans[i][j-1][0] == mx) r1 += ans[i][j-1][1];
      if(A[i][j] == mx) r1 += 1;
      if(ans[i-1][j][0] == mx && ans[i][j-1][0] == mx && ans[i-1][j-1][0] == mx) r1 -= ans[i-1][j-1][1];
      ans[i][j] = {mx, r1};
      //cout << "ans[" << i-1 << ", " << j << "] = " << ans[i-1][j][0] << " " << ans[i-1][j][1] << " - ";
      //cout << "ans[" << i << ", " << j-1 << "] = " << ans[i][j-1][0] << " " << ans[i][j-1][1] << " - ";
      //cout << "ans[" << i << ", " << j << "] = " << ans[i][j][0] << " " << ans[i][j][1] << "\n";
    }
  }
  int Q; cin >> Q;
  while(Q--){
    int x, y; cin >> x >> y;
    cout << ans[x][y][0] << " " << ans[x][y][1] << "\n";
  }
}
