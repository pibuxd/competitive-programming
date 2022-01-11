#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define INF (int)1e17

int n;
vector<int> a;

signed main(){
  fastio;
  cin >> n;
  a.assign(n+1, 0);

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  int sum = 0, sum1 = -INF, sum2 = INF;
  int sum_max = sum1, sum_min = sum2;

  for(int i = 1; i <= n; i++){
    sum += a[i];

    sum1 = max(sum1+a[i], a[i]);
    sum2 = min(sum2+a[i], a[i]);
    sum_max = max(sum_max, sum1);
    sum_min = min(sum_min, sum2);
  }
  
  if(sum_min == sum)
    cout << sum_max;
  else
    cout << max(sum - sum_min, sum_max);
}