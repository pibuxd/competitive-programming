#include "bits/stdc++.h"
using namespace std;
// find union

int N, x, y, sum;

void Union(vector<vector<pair<int, int>>> &parent) {
  int a = x, aa = x, b = y, bb = y;

  if(parent[a][b] == 0) {

  }

  while(parent[a][b] > 0) {
    a = parent[a][b];
  }
}

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;

  while(t--) {
    sum = 1;
    
    cin >> N;
    N *= N; // pole tablicy
    vector<vector<pair<int, int>>> parent(N+1, vector<pair<int, int>>(N+1));

    for(int i = 1; i < N; i++) { // wykonuje sie N-1 razy, bo ostatniej operacji nie trzeba obliczac
      cin >> x >> y;

      Union(parent);

      cout << sum << ' ';
    }
    
    cin >> x >> y; // zawsze ostatniego dnia zjadaja ostatnie wolne pole
    cout << "0\n"; // planszy, wiec zostaje 0 czesci (unions)
  }
}
