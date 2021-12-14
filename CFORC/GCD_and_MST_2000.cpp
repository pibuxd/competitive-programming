// * Number theory (math)
// * DSU
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int t, n, p;
long long ans;
vector<int> a;
vector<bool> connected;
vector<pair<int, int>> mins;

void mst(int start){
  int val = a[start];
  if(val >= p)
    return;

  // go to right
  int i = start;
  while(i < n-1){
    if(a[i+1] % val == 0 && !connected[i]){
      connected[i] = true;
      ans += val;
      i++;
    }
    else
      break;
  }

  // go to left
  i = start;
  while(i > 0){
    if(a[i-1] % val == 0 && !connected[i-1]){
      connected[i-1] = true;
      ans += val;
      i--;
    }
    else
      break;
  }
}

int main(){
  fastio;
  cin >> t;

  while(t--){
    cin >> n >> p;
    a = vector<int>(n);
    mins = vector<pair<int, int>>(n);
    connected = vector<bool>(n);
    ans = 0;

    for(int i = 0; i < n; i++){
      cin >> a[i];
      mins[i] = {a[i], i};
    }
    sort(mins.begin(), mins.end());

    for(auto x : mins){
      mst(x.second);
    }

    for(int i = 0; i < n-1; i++){
      if(!connected[i])
        ans += p;
    }
    cout << ans << "\n";
  }
}