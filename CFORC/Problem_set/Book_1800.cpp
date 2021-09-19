#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int solve(){
  int n;
  vector<vector<int>> G;
  vector<int> ind;
  
  cin >> n;
  G.assign(n+1, vector<int>());
  ind.assign(n+1, 0);

  for(int i = 1; i <= n; i++){
    int ile;
    cin >> ile;
    while(ile--){
      int x;
      cin >> x;
      G[x].push_back(i);
      ind[i]++;
    }
  }
  
  vector<int> order;
  set<int> S;
  for(int i = 1; i <= n; i++) if(!ind[i]) S.insert(i);


  while(!S.empty()){
    auto it = S.begin();
    if(order.empty())
      it = S.upper_bound(0);
    else
      it = S.upper_bound(order.back());
    if(it == S.end())
      it = S.begin();
    int v = *it;
    // cout << v << ":";
    S.erase(it);

    order.push_back(v);

    for(int x : G[v]){
      ind[x]--;
      if(!ind[x]) 
        S.insert(x);
    }
  }

  if(order.size() != n) return -1;
  // for(int x : order) cout << x << " ";
  int ans = 0;
  int last = 0;
  for(int x : order){
    if(x < last)
      ans++;
    last = x;
  }

  return ans+1;
}

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--)
    cout << solve() << "\n";
}