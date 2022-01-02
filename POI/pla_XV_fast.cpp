// * Monotone Queue
// * O(n)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n;
  cin >> n;

  int ans = 0;
  stack<int> s;

  for(int i = 1; i <= n; i++){
    int _, a; cin >> _ >> a;
    
    while(!s.empty() && s.top() > a){
      s.pop();
      ans++;
    }
    if(s.empty() || s.top() < a)
      s.push(a);
  }

  ans += s.size();

  cout << ans;
}