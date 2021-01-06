#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int m, n, a; cin >> m; int V[m]; long long sum_pref[m+2];
  for(int i = 0; i < m; i++){ cin >> V[i]; }
  sort(V, V + m); sum_pref[0] = 0;
  for(int i = 0; i < m; i++){ sum_pref[i+1] = (sum_pref[i] + V[i]); } cin >> n;
  for(int i = 0; i < n; i++){ cin >> a; cout << sum_pref[a] << '\n'; }
}
