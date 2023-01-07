#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

signed main(){
  fastio;
  int t; cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> q;
    int sum = 0;
    for(int i = 1; i <= n; i++){
      int p; cin >> p;
      q.push(p);
      sum += p;
    }
    for(int i = 1; i <= m; i++){
      int b; cin >> b;
      int g = q.top();
      sum += b-g;
      q.pop();
      q.push(b);
    }
    cout << sum << "\n";
  }
}
