#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long n, r, k;
vector<array<long long, 2>> in;

long long solve(){
  long long ans = 0;
  long long average = 0;

  if(r < k) return -1;
  
  for(long long i = 0; i < n; i++){
    cin >> in[i][1] >> in[i][0];
    average += in[i][1];
  }

  k *= n;
  long long to_add = k-average;
  sort(in.begin(), in.end());

  for(long long i = 0; i < n; i++){
    if(to_add <= 0)
      return ans;
    
    if(in[i][1] < r){
      long long can = r-in[i][1];

      if(to_add - can <= 0){
        ans += in[i][0]*to_add;
        to_add = 0;
        in[i][0]++;
      }
      else{
        ans += in[i][0]*can;
        to_add -= can;
        in[i][0]++;
      }
    }
  }

  return ans;
}

int main(){
  fastio;
  cin >> n >> r >> k;
  in.resize(n);
  cout << solve();
}