#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define uint unsigned int

int n, m, q;
uint M = 1e9+7;
vector<vector<uint>> fen;

void add(int idx, uint val, vector<uint> &f){
  for(; idx <= q; idx += idx & -idx)
    f[idx] = (f[idx] + val) % M;
}

uint sum(int idx, vector<uint> &f){
  uint res = 0;
  for(; idx >= 1; idx -= idx & -idx)
    res = (res + f[idx]) % M;
  return res;
}

signed main(){
  fastio;
  int t; cin >> t;

  for(int test = 1; test <= t; test++){
    cin >> n >> m;

    vector<int> av(n+1), _av(n);
    for(int i = 1; i <= n; i++){
      cin >> av[i];
      _av[i-1] = av[i];
    }
    if(m == 1){
      cout << "Case #" << test << ": " << n << "\n";
      continue;
    }
    unordered_map<int, int> id;
    sort(all(_av));
    int last = 0;
    q = 0;
    for(int a : _av)
      if(last != a)
        id[a] = ++q, last = a;
    
    fen.assign(m+1, vector<uint>(q+1, 0));
    uint ans = 0;
    for(int i = 1; i <= n; i++){
      int a = id[av[i]];
      
      add(a, 1, fen[1]);
      for(int j = 1; j <= m; j++)
        add(a, sum(a-1, fen[j-1]), fen[j]);

      ans = (ans + sum(a-1, fen[m-1])) % M;
    }
    
    cout << "Case #" << test << ": " << ans << "\n";
  }
}
