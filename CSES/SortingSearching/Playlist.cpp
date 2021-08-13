// * Sliding window
// * Data structure
// explanation: two pointers sliding inside list
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, ans;
vector<int> a;
set<int> s;

int main(){
  fastio;
  cin >> n;
  a.resize(n);
  for(int &i : a) cin >> i;

  int r = -1;
  for(int i = 0; i < n; i++){
    while(r < n-1 && !s.count(a[r+1]))
      s.insert(a[++r]);

    s.erase(a[i]);
    ans = max(ans, r-i+1);
  }

  cout << ans;
}