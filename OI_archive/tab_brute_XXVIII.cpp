#include "bits/stdc++.h"
using namespace std;

void printTab(vector<vector<bool>> T, int n, int m){
  for(int i = 1; i <= n; i++){
    cerr << '\n';
    for(int j = 1; j <= m; j++){
      cerr << T[i][j] << ' ';
    }
  }
  cerr << "\n\n";
}

void flipTab(vector<vector<bool>> &T, int a, int b, int x, int y){
  for(int i = a; i <= x; i++){
    for(int j = b; j <= y; j++)
      T[i][j] = !T[i][j];
  }
}

int minMoves(vector<vector<bool>> T, int n, int m){
  int moves = 0;
  int start = m;

  while(start > 0){
    int last = -1;
    bool wasZero = false, was = false;

    for(int i = 1, x = start; i <= n; i++){
      if(T[i][x] == 1){
        last = i;

        if(!wasZero && was){
          wasZero = true;
          was = false;
        }
      } else{
        was = true;
      }
    }

    if(last == -1)
      start--;

    if(last > 0){
      flipTab(T, 1, 1, last, start);
      moves++;
    }
    if(!wasZero && last > 0)
      start--;

    //cout << start;
  }

  //printTab(T, n, m);
  return moves;
}

int main(){ //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, q; cin >> n >> m >> q;
  vector<vector<bool>> T(n+1, vector<bool>(m+1));

  while(q--){
    int a, b, x, y; cin >> a >> b >> x >> y;
    flipTab(T, a, b, x, y);
    //printTab(T, n, m);
    cout << minMoves(T, n, m) << '\n';
  }
}
