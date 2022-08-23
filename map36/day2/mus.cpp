#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> a;

signed main(){
  fastio;
  cin >> n;
  a.resize(n+1);

  int dwa = 0, jed = 0;
  for(int i = 1; i <= n; i++){
    char c; cin >> c;
    a[i] = (c == '1' ? 1 : 2);
    dwa += (a[i] == 2);
    jed += (a[i] == 1);
  }

  int _jed = 0, czek = -1, d = dwa;

  for(int i = n; i >= 1 && d; i--){
    if(a[i] == 2) d--;
    if(a[i] == 1) _jed++, czek = max(-1, czek-1);
    else if(_jed > 0){
      czek++;
    }

  }
  int x = 1;
  while(x <= n && a[x] != 2)
    x++;

  cout << max(jed-(x-1) + max(czek, 0), 0) << "\n";
}