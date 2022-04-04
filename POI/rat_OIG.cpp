// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k, x, y;

bool check(int a, int b){
  int difx = abs(a-x), dify = abs(b-y);

  float diff = sqrt((float)difx*(float)difx + (float)dify * (float)dify);
  if(diff > (float)k)
    return false;
  return true;
}

int main(){
  fastio;
  cin >> n >> k >> x >> y;
  
  int ans = 0;
  while(n--){
    int a, b;
    cin >> a >> b;
    if(!check(a, b))
      ans++;
  }

  cout << ans;
}