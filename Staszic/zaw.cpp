#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n;
vector<array<int, 3>> a, b, c;

bool cb(const array<int, 3> &v1, const array<int, 3> &v2){
  return v1[1] < v2[1];
}

bool cc(const array<int, 3> &v1, const array<int, 3> &v2){
  return v1[2] < v2[2];
}

int isw(int x, int y){
  return x >= y;
}

int main(){
  fastio;
  cin >> n;
  
  a.resize(n+1);
  for(int i = 1; i <= n; i++)
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  b = c = a;
  
  sort(all(a));
  sort(all(b), cb);
  sort(all(c), cc);
  
  int la, lb, lc;
  la = lb = lc = n;
  
  while(la && lb && lc){
    int _la = la, _lb = lb, _lc = lc;
    if(isw(a[la][1], b[lb][1]) || isw(a[la][2], c[lc][2]))
      _la--;
    if(isw(b[lb][0], a[la][0]) || isw(b[lb][2], c[lc][2]))
      _lb--;
    if(isw(c[lc][0], a[la][0]) || isw(c[lc][1], b[lb][1]))
      _lc--;
    if(_la == la && _lb == lb && _lc == lc) break;
    la = _la, lb = _lb, lc = _lc;
  }
  
  if(!la || !lb || !lc) cout << -1 << "\n";
  else cout << a[la][0] + b[lb][1] + c[lc][2] << "\n";
}
