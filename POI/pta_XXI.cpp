// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k;
vector<int> t;

struct DQ{
  deque<int> dq;

  void insert(int x){
    while(!dq.empty() && dq.back() < x)
      dq.pop_back();
    dq.push_back(x);
  }

  void erase(int x){
    if(!dq.empty() && dq.front() == x)
      dq.pop_front();
  }

  int val(){
    return dq.front();
  }
};

int solve(){
  vector<int> dp(n+1);
  DQ dq0, dq1;

  int val0 = 0, val1 = 1;
  int x0 = 0, x1 = 0;
  for(int i = 2; i <= k+1 && i <= n; i++){
    if(t[i] >= t[1]){
      dp[i] = 1, x1++;
      dq1.insert(t[i]);
    }
    else{
      dp[i] = 0, x0++;
      dq0.insert(t[i]);
    }
  }

  int l = 1+k + 1;

  while(l <= n){
    if(x0 == 0){
      swap(dq0, dq1);
      val0 = val1, val1++;
      x0 = x1, x1 = 0;
    }

    int hi = dq0.val();
    if(hi <= t[l])
      dp[l] = val0 + 1;
    else
      dp[l] = val0;

    if(dp[l-k] == val0){
      dq0.erase(t[l-k]);
      x0--;
      if(x0 == 0){
        swap(dq0, dq1);
        val0 = val1, val1++;
        x0 = x1, x1 = 0;
      }
    }
    else{
      dq1.erase(t[l-k]);
      x1--;
    }

    if(dp[l] == val0){
      dq0.insert(t[l]);
      x0++;
    }
    else{
      val1 = dp[l];
      dq1.insert(t[l]);
      x1++;
    }
    if(val1 < val0){
      swap(dq0, dq1);
      swap(val0, val1);
      swap(x0, x1);
    }
    l++;
  }

  return dp[n];
}

int main(){
  fastio;
  cin >> n;
  t.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> t[i];

  int q;
  cin >> q;
  while(q--){
    cin >> k;
    cout << solve() << "\n";
  }
}