// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int n, A[10], V[10] = {0}, Z[10], s; double p, w; //zakodowywanie
  cin >> n; string S[n], K[n];
  for(int it = 0; it < n; it++){ cin >> S[it];
    for(int i = 0; i < S[it].size(); i++){
      p = S[it].size()-1-i;
      w = pow(10, p);
      A[(S[it][i]-97)] = 1;
      V[(S[it][i]-97)] += w;
    }} //odkodowywanie
vector<pair<int,int>> T;
for(int i = 0; i < n; i++){ T.push_back(make_pair(V[i], i)); }
sort(T.rbegin(), T.rend());
for(int i = 0; i < n; i++){ if(A[T[i].second] == 0){ s = i+1; }}
for(int i = 1; i < s; i++){ T[i].first = i; }
}
