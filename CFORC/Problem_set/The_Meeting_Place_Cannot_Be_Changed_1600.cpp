#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, mxX;
vector<int> x, v;

bool check(double t){
  double mxL = -1e9+1, mnR = 1e9+1;
  for(int i = 1; i <= n; i++){
    mxL = max(mxL, x[i]-t*v[i]);
    mnR = min(mnR, x[i]+t*v[i]);
  }
  if(mxL <= mnR)
    return true;
  return false;
}

int main(){
  fastio;
  cin >> n;
  x.resize(n+1);
  v.resize(n+1);
  mxX = 0;

  for(int i = 1; i <= n; i++){
    cin >> x[i];
    mxX = max(mxX, x[i]);
  }
  for(int i = 1; i <= n; i++)
    cin >> v[i];

  double prec = 0.0000001;
  double l = 0.0, r = mxX, ans = 0;
  while(fabs(l-r) >= prec){
    double m = (l+r)/2.0;
    if(check(m)){
      ans = m;
      r = m-prec;
    }
    else{
      l = m+prec;
    }
  }

  cout << setprecision(8) << ans;
}