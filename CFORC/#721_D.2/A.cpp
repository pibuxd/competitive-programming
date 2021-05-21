#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

auto solve(int n){
  bitset<32> x(n);
  int end;

  for(int i = 0; i <= 31; i++){
    if(x[i] == 1){
      end = i;
      break;
    } 
  }

  string b = "0";
  int len = 32-end;
  while(len--) b += '1';
  return b;
}

int main(){ fastio;
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    cout << solve(n) << "\n";
  }
}