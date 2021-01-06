#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int V[n], b;
  bitset<100000> nastr, odw;
  vector<vector<int>> G;

  for(int i = 0; i < n; i++){
    cin >> V[i];
  }
  for(int i = 0; i < n; i++){
    cin >> b;
    nastr[i] = b;
    odw[i] = false;
  }

  int w = 0;
  for(int i = 0, j = 0; i < n; i++, j = i){ cout << "jd";
    if(!odw[V[i]]){
      odw[V[i]] = true;
      while(V[j] > 0){ cout << "jd";
        odw[V[j]] = true;
        G[w].push_back(V[j]);
        cout << V[j] << ' ';
        j = V[j] - 1;
      }
      w++;
      cout << '\n';
    }
  }
  cout << "jd";
  for(int i = 0; i < w; i++){ cout << "jd";
    for(int j = 0; j < G[i].size(); j++)
      cout << G[i][j] << ' ';
    cout << '\n';
  }
}
