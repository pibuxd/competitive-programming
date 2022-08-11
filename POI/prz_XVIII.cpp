#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k, m;
vector<int> a, b, kol, gd, tab;
vector<vector<int>> p, A, B;

int main(){
  fastio;
  cin >> n >> k >> m;
  a.resize(n+1);
  b.resize(n+1);
  gd.resize(n+1);
  kol.resize(n+1);
  p.resize(k+1);
  A.resize(k+1);
  B.resize(k+1);

  for(int i = 1; i <= m; i++){
    int x, y;
    cin >> x >> y;
    p[x].push_back(y);
    p[y].push_back(x);
  }

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    A[a[i]].push_back(i);
  }
  for(int i = 1; i <= n; i++){
    cin >> b[i];
    B[b[i]].push_back(i);
  }

  for(int i = 1; i <= k; i++){
    if(A[i].size() != B[i].size())
      goto nie;

    for(int j = 0; j < A[i].size(); j++){
      gd[A[i][j]] = B[i][j];
    }
  }

  for(int i = 1; i <= n; i++){
    kol[i] = n-gd[i]+1;
  }

  // for(int i = 1; i <= n; i++) cout << gd[i] << " ";
  // cout << "\n";
  // for(int i = 1; i <= n; i++) cout << kol[i] << " ";
  // cout << "\n";

  tab.assign(k+1, n+1);
  for(int i = 1; i <= n; i++){
    for(int x : p[a[i]]){
      if(tab[x] < kol[i])
        goto nie;
    }

    tab[a[i]] = min(tab[a[i]], kol[i]);
  }

  tab.assign(k+1, 0);
  for(int i = n; i >= 1; i--){
    for(int x : p[a[i]]){
      if(tab[x] > kol[i])
        goto nie;
    }

    tab[a[i]] = max(tab[a[i]], kol[i]);
  }

  if(false){
    nie:
    cout << "NIE\n";
    return 0;
  }
  cout << "TAK\n";
}