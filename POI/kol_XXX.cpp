#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int m, p, n;
vector<vector<int>> v; // '.' = -1
vector<vector<int>> ruch; // ostatni moment gdy byl na tych wspolrzednych

int main(){
  fastio;
  cin >> m >> p >> n;

  v.assign(m+1, vector<int>(m+1, -1));
  ruch.assign(m+1, vector<int>(m+1, -1));

  for(int i = 1; i <= p; i++){
    int w, k, c; cin >> w >> k >> c;
    v[w][k] = c;
  }
  
  int ci = 1, cj = 1, nr = 0;
  vector<int> waz = {0};
  ruch[1][1] = 0;

  for(int i = 1; i <= n; i++){
    char z; cin >> z;
    
    switch(z){
      case 'P':
        cj++;
        break;
      case 'D':
        ci++;
        break;
      case 'L':
        cj--;
        break;
      case 'G':
        ci--;
        break;
    }

    if(z == 'Z'){
      int zi, zj; cin >> zi >> zj;
      int znr = ruch[zi][zj];

      if(znr == -1){
        cout << -1 << "\n";
        continue;
      }
      if(waz.size() >= nr-znr+1)
        cout << waz[waz.size() - (nr-znr+1)] << "\n";
      else cout << -1 << "\n";

    } else{
      if(v[ci][cj] != -1){
        waz.push_back(v[ci][cj]);
        v[ci][cj] = -1;
      }

      ruch[ci][cj] = ++nr;
    }
  }
}
