#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<float> v;

bool check(float x){
  int used = n-1;
  float last = v[1] + x;

  for(int i = 1; i <= m; i++){
    if(used < 0) return false;
    if(used >= m) return true;
    if(fabs(last-v[i]) > x){
      used--;
      last = v[i] + x;
    }
  }

  if(used >= 0)
    return true;
  return false;
}

float _round(float x, float p){
  float f = floor(x);
  float dif = x - f;
  while(dif - p >= 0){
    dif -= p;
  }

  float ans = x - dif;
  return ans;
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

    float ans = 0.0, l = 0.0, r = 14185.6, p = 0.01;
    while(fabs(l-r) >= p){
      float mid = (l+r)/2.0;
      if(check(mid)){
        ans = mid;
        r = mid;
      }
      else
        l = mid;
    }    
  
    cout << setiosflags(ios::fixed) << setprecision(1) << ans << "\n";
  }
}