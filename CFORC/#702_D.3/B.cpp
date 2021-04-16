#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;

  int t; cin >> t;

  while(t--){
    int n, ans = 0;
    cin >> n;
    vector<int> remain(3);

    for(int i = 0, x; i < n; i++){
      cin >> x;
      remain[x%3]++;
    }

    int k = n / 3; // a number in every remainder

    if(remain[0] > remain[1] && remain[1] > remain[2]){ // 0 > 1 > 2
      ans += remain[2] - remain[0];
      ans += remain
    } else if(remain[0] > remain[1] && remain[1] > remain[2]){

    }
  }
}