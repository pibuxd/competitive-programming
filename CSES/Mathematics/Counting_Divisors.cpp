// * Count divisors of the number
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int count_divisors_of(int a){
  int ans = 0;
  
  for(int i = 1; i*i <= a; i++)
    if(a % i == 0)
      ans += 1 + (a/i != i);
  
  return ans;
}

int main(){
  fastio;
  int t; cin >> t;
  while(t--){
    int a; cin >> a;
    cout << count_divisors_of(a) << "\n";
  }
}