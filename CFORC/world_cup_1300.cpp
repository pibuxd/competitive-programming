#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n;
  cin >> n;

  vector<int> a(n);
  vector<long long> p(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  for(int i = 0; i < n; i++){
    a[i] -= i;
    if(a[i] <= 0)
      p[i] = i;
    else{
      int temp = a[i] / n;
      p[i] += i;
      p[i] += temp;
      a[i] -= n * temp;
      if(a[i] > 0) p[i] += n;
      a[i] = 0;
    }
  }

  long long minimum = LONG_LONG_MAX;
  int ans;
  for(long long x : p){
    minimum = min(minimum, x);
  }
  cout << minimum + 1;
}