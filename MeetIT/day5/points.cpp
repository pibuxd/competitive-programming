#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> x, y;

int _round(float x){
  if(float(x - (int)x) > 0.5)
    return (int)x+1;
  return (int)x;
}

int main(){
  fastio;
  cin >> n;
  x = y = vector<int>(n+1);

  for(int i = 1; i <= n; i++){
    cin >> x[i] >> y[i];
  }

  int sr = 0;
  for(int i = 1; i <= n; i++){
    sr += x[i];
  }
  
  sr = _round((float)sr/n);
  cout << "SR: " << sr << " ";
  int ans = 0;

  for(int i = 1; i <= n; i++){
    ans += abs(sr-x[i]);
  }

  cout << "ANS1: " << ans << " ";
  sort(y.begin(), y.end());

  int start = y[1]+1, m = y[1]-1;
  for(int i = 2; i < n; i++){
    if(y[i] < y[i+1])
      ans += abs(start-y[i]), start++;
    else if(abs(start-y[i]) > abs(m-y[i]) && m > 0)
      ans += abs(m-y[i]), m--;
    else
      ans += abs(start-y[i]), start++;
  }

  cout << ans;
}