// binary search (upper bound here)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n;
vector<int> a;
vector<vector<int>> idx;

string ans(vector<int> &v){
  int k = 0;
  for(int x : v){
    auto it = upper_bound(all(idx[x]), k);
    if(it == idx[x].end())
      return "NIE";
    k = *it;
  }

  return "TAK";
}

int main(){
  fastio;
  cin >> n;
  a.assign(n+1, 0);
  idx.assign(1000000, {});

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    idx[a[i]].push_back(i);
  }
  
  int t;
  cin >> t;
  while(t--){
    int m; cin >> m;
    vector<int> b;
    while(m--){
      int x; cin >> x;
      b.push_back(x);
    }

    cout << ans(b) << "\n";
  }
}