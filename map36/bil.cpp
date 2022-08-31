#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n, mxa = 1e6;
vector<int> a, bit;

void add(int idx, int val){
  for(; idx <= mxa; idx += idx & -idx)
    bit[idx] += val;
}

int sum(int idx){ // sum on range (1 -> idx)
  int res = 0;
  for(; idx > 0; idx -= idx & -idx)
    res += bit[idx];
  return res;
}

signed main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  bit.resize(mxa+1);
  vector<vector<int>> aiv(mxa+1);

  for(int i = 1; i <= n; i++){
    int p; cin >> p;
    a[i] = p;
    aiv[p].push_back(i);
  }

  int ans = 0;

  for(int i = 1; i <= n; i++){
    ans += sum(a[i]);
    if(a[i] > i)
      add(i, 1);
    
    for(int x : aiv[i])
      if(x < i)
        add(x, -1);
  }

  cout << ans << "\n";
}
