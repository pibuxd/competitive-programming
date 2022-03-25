// * 2p, sliding window
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

signed main(){
  fastio;
  int n, k;
  cin >> n >> k;

  vector<int> x(n+1);
  for(int i = 1; i <= n; i++) cin >> x[i];

  map<int, int> cnt;
  int l = 1, r = 1;
  int distinct = 1;
  cnt[x[1]] = 1;

  int sum = 1;

  while(r < n){
    if(cnt[x[r+1]] == 0 && distinct == k){
      if(l != r){
        cnt[x[l]]--, distinct -= (cnt[x[l]] == 0);
        l++;

      } else{ // distinct was and is equal to 1
        cnt[x[l]]--, cnt[x[l+1]]++;
        l++, r++;
        sum++;
      }
    } else{
      distinct += (cnt[x[r+1]] == 0);
      cnt[x[r+1]]++;
      r++;
      sum += (r-l+1);
    }
  }

  cout << sum;
}