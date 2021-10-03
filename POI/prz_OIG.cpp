#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n, m;
  cin >> n >> m;
  vector<int> prz(n+1);

  int mx = 0, _mx = 0;
  while(m--){
    int x;
    cin >> x;

    if(x == n+1){
      _mx = mx;
      continue;
    }
    prz[x] = max(prz[x], _mx);
    prz[x]++;
    mx = max(mx, prz[x]);
  }

  for(int i = 1; i <= n; i++){
    prz[i] = max(prz[i], _mx);
    cout << prz[i] << " ";
  }
}