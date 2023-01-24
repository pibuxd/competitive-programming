#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n;
  cin >> n;

  int dpa = 0, dpb = 0, dpc = 0;
  while(n--){
    int a, b, c; cin >> a >> b >> c;
    int _dpa = max(dpb + a, dpc + a);
    int _dpb = max(dpa + b, dpc + b);
    int _dpc = max(dpa + c, dpb + c);
    dpa = _dpa, dpb = _dpb, dpc = _dpc;
  }

  cout << max({dpa, dpb, dpc}) << "\n";
}
