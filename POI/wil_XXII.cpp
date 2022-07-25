#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, p, d;
vector<int> w, dsum; // dsum-suma deski zaczynajacej sie na pozycji i
deque<int> DQ;

void initdsum(){
  int dsumsize = n-d+1;
  dsum.assign(dsumsize+1, 0);
  int sum = 0, r = 0;
  while(r < d)
    sum += w[++r];
  dsum[1] = sum;
  int l = 1;
  while(r < n)
    sum += w[++r], sum -= w[l++], dsum[l] = sum;
}

void dqadd(int element){
  while(!DQ.empty() && DQ.back() < element)
    DQ.pop_back();
  DQ.push_back(element);
}

void dqrem(int element){
  if(!DQ.empty() && DQ.front() == element)
    DQ.pop_front();
}

int dqmx(){
  return DQ.front();
}

signed main(){
  fastio;
  cin >> n >> p >> d;
  
  w.assign(n+1, 0);
  for(int i = 1; i <= n; i++)
    cin >> w[i];

  initdsum();

  int l = 1, r = d, sum = 0, ans = d;
  for(int i = 1; i <= d; i++)
    sum += w[i];
  dqadd(dsum[1]);

  while(l <= n){
    while(sum - dqmx() > p){
      sum -= w[l];
      dqrem(dsum[l]);
      if(l == n) break;
      l++;
    }

    ans = max(ans, r-l+1);
    if(r == n)
      break;
    r++;
    sum += w[r];
    dqadd(dsum[r-d+1]);
  }

  cout << ans << "\n";
}
