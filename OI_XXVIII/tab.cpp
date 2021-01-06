#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void flipTab(vector<vector<bool>> &T, int a, int b, int x, int y){
  for(int i = a; i <= x; i++){
    for(int j = b; j <= y; j++)
      T[i][j] = !T[i][j];
  }
}

int minMoves(const vector<vector<bool>> &T, int n, int m){
  vector<int> licz(n+1);
  bool x, which, first;

  for(int it = m, ile = 1, last = -1; it > 0; it--, ile = 1, last = -1){
    if(licz[1] % 2 == 0)
      first = T[1][it];
    else
      first = !T[1][it];

    which = first;
    for(int i = 1; i <= n; i++){
      if(licz[i] % 2 == 0)
        x = T[i][it];
      else
        x = !T[i][it];

      if(x){
        if(!which){
          ile++;
          which = 1;
        }

        last = i;

      } else{
        if(which){
          ile++;
          which = 0;
        }
      }
    }

    if(last == -1)
      goto skip;
    else if(last < n)
      ile--;

    which = first;

    for(int i = 1; i <= n; i++){
      if(licz[i] % 2 == 0)
        x = T[i][it];
      else
        x = !T[i][it];

      if(x){
        if(!which){
          ile--;
          which = 1;
        }

        last = i;

      } else{
        if(which){
          ile--;
          which = 0;
        }
      }

      licz[i] += ile;
    }

    skip:;
  }

  return licz[1];
}

int main(){ fastio;
  int n, m, q; cin >> n >> m >> q;
  vector<vector<bool>> T(n+1, vector<bool>(m+1));

  while(q--){
    int a, b, x, y; cin >> a >> b >> x >> y;
    flipTab(T, a, b, x, y);
    cout << minMoves(T, n, m) << '\n';
  }
}
