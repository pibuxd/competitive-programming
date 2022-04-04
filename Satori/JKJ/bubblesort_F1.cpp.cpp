// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

#define pu push_back

int main(){ //ios_base::sync_with_stdio(0);
  int t;
  cin >> t;

  while(t--){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> V;
    vector<int> temp, sorted;

    for(int i = 0, p; i < n; i++){
      cin >> p;
      temp.pu(p);
      sorted.pu(p);
    }
    sort(sorted.begin(), sorted.end());
    int bledy = 0;
    for(int i = 0; i < n; i++){
      if(temp[i] != sorted[i]){
        bledy++;
      }
    }
    int rank[m];
    rank[(bledy/2)] = 0;
    V.pu(temp);


    for(int i = 1; i < m; i++){
      vector<int> temp;
      for(int j = 0, p; j < n; j++){
        cin >> p;
        temp.pu(p);
      }

      int bledy = 0;
      for(int i = 0; i < n; i++){
        if(temp[i] != sorted[i]){
          bledy++;
        }
      }
      rank[(bledy/2)] = i;
      V.pu(temp);
    }
    cout << '\n';
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cout << V[rank[i]][j] << ' ';
      }
      cout << '\n';
    }
  }
}
