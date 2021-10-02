#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

bool check(float x, int n, int m, const vector<int> &v){
  int used = n-1;
  float last = (float)v[m] - (float)x;

  for(int i = m; i >= 1; i--){
    if(fabs((float)last-(float)v[i]) > (float)x){
      used--;
      // cout << used << ", ";
      last = (float)v[i] - (float)x;
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
    int n, m;
    cin >> n >> m;
    vector<int> v(m+1);

    for(int i = 1; i <= m; i++)
      cin >> v[i];

    float ans = 0.0, l = 0.0, r = 1000000.0, p = 0.0001;
    while(fabs((float)l-(float)r) >= (float)p){
      float mid = ((float)l+(float)r)/(float)2.0;
      if(check(mid, n, m, v)){
        ans = (float)mid;
        r = (float)mid - (float)p;
      }
      else
        l = (float)mid + (float)p;
    }

    cout << check((float)20.0, n, m, v);
    cout << setiosflags(ios::fixed) << setprecision(1) << (float)ans << "\n";
  }
}