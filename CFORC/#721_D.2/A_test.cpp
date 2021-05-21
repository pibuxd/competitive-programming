#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
int solve(int x){
  int v = x;
  for(int i = x-1; i >= 0; i--){
    v = v & i;
    if(v == 0) return i;
  }
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