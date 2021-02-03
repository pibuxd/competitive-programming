#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
  int p, m, n = 0, a, b, L[200];
  cin >> p >> m;
  for(int i = 0; i < p; i++){
    L[i] = 0;
  }
  vector<pair <int, int>> P;
  for(int i = 0; i < p; i++){
    cin >> a >> b;
    P.push_back(make_pair(a, b));
  }
  sort(P.begin(), P.end());
  for(int i = 0; i < p; i++){
    if(P[i].first == 0){
      L[n] += P[i].second;
      n++;
      goto koniec;
    }
    if(P[i].first == P[i+1].first){
      L[n] += P[i].second + P[i+1].second;
      n++; i++;
      goto koniec;
    }
    if(P[i].first != P[i+1].first){
      L[n] += P[i].second;
      n++; i++;
      L[n] += P[i].second;
    }
    koniec:;
  }
  sort(L, L+n);
  int V[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      V[i][j] = 0;
    }
  }
  for(int i = 1; i <= m; i++){
    if(L[i] <= i){
      V[0][i] = L[i];
    }
  }
  for(int i = 1; i < n; i++){
    for(int j = 0; j <= m; j++){
      if(i >= L[i] && (L[i]+V[i-1][j-L[i]])){
        V[i][j] =
      }
    }
  }
}
