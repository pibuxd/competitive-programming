// * Binary search
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int n, m;
vector<int> v;

bool check(float x){
  int used = n-1;
  float last = (float)v[1] + x;

  for(int i = 1; i <= m; i++){
    if(used < 0) return false;
    if(used >= m) return true;
    if(fabs(last-(float)v[i]) > x){
      used--;
      last = (float)v[i] + x;
    }
  }

  if(used >= 0)
    return true;
  return false;
}

int main(){
  fastio;
  int t;
  cin >> t;
  
  while(t--){
    cin >> n >> m;
    v.assign(m+1, 0.0);

    for(int i = 1; i <= m; i++)
      cin >> v[i];
    sort(v.begin(), v.end());

    float l = 0.0, r = 14185.6, p = 0.01;
    while(fabs(l-r) >= p){
      float mid = (l+r)/2.0;
      if(check(mid)){
        r = mid;
      }
      else
        l = mid;
    }    
  
    cout << setiosflags(ios::fixed) << setprecision(1) << r << "\n";
  }
}