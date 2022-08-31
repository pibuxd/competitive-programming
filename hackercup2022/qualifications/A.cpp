#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()


int main(){
  fastio;
  int t; cin >> t;

  for(int _t = 1; _t <= t; _t++){
    cout << "Case #" << _t << ": ";

    int n, k;
    cin >> n >> k;
    
    set<int> s1, s2;
    bool ans = true;
    for(int i = 1; i <= n; i++){
      int a; cin >> a;
      int s1c = s1.count(a), s2c = s2.count(a);
      int s1s = s1.size(), s2s = s2.size();
      if((s1c && s2c) || (s1c && s2s >= k) || (s2c && s1s >= k) || (s1s >= k && s2s >= k)) ans = false;
      else if(s2c || (!s1c && s1s < k)) s1.insert(a);
      else if(s1c || (!s2c && s2s < k)) s2.insert(a);
    }

    cout << (ans ? "YES" : "NO") << "\n";
  }
}
