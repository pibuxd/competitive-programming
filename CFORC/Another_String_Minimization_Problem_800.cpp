#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    vector<int> a(n+1);
    vector<array<int, 3>> p;

    for(int i = 1; i <= n; i++){
      cin >> a[i];
      p.push_back({min(a[i], m+1-a[i]), max(a[i], m+1-a[i]), i});
    }

    sort(p.begin(), p.end());
    vector<bool> vis(n+1), str(m+1);

    for(auto x : p){
      if(vis[x[2]]) continue;

      if(str[x[0]]) str[x[1]] = true;
      else str[x[0]] = true;
      vis[x[2]] = true;
    }

    for(int i = 1; i <= m; i++) cout << (str[i] ? 'A' : 'B');
    cout << "\n";
  }
}
