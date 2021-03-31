#include <bits/stdc++.h>
using namespace std;
//ten program jest niedopracowany ale pomysł dobry
int main(){ ios_base::sync_with_stdio(0);
  int n, it = 0; cin >> n; int A[n], B[n], R[n];
  vector<pair<int, int>> V;
  for(int i = 0; i < n; i++){ cin >> A[i] >> B[i];
    V.push_back(make_pair(A[i], B[i]));
  } sort(V.rbegin(), V.rend());
  for(int i = 0; i < n; i++){ R[i] = V[i].second - V[i].first; }
  while(it < n){
    if(R[it] - V[it+1].first < R[it+1]) R[it+1] = R[it] - V[it+1].first;
    it++;
  }
  cout << R[it-1];
}
