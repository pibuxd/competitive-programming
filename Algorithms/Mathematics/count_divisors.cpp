// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Count divisors of the number
#include <bits/stdc++.h>
using namespace std;

int count_divisors_of(int a){
  int ans = 0;

  for(int i = 1; i*i <= a; i++)
    if(a % i == 0)
      ans += 1 + (a/i != i);
  
  return ans;
}

int main(){
  int a;
  cin >> a;
  cout << count_divisors_of(a) << "\n";
}