#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

auto brute(int n){
  vector<int> p;
  for(int i = 1; i <= n-1; i++)
    p.push_back(i);

  int mx = 1;
  vector<int> ans;
  do{
    int sum = 1;
    for(int i = 1; i <= n-1; i++){
      sum *= p[i-1];
      if(sum % n == 1 && mx < i){
        mx = max(mx, i);
        ans.assign(i, 0);
        copy(p.begin(), p.begin()+i, ans.begin());
      }
    }
  } while(next_permutation(p.begin(), p.end()));

  return ans;
}

signed main(){
  int n;
  cin >> n;

  // auto ans = brute(n);
  // cout << ans.size() << "\n";
  // for(auto i : ans) cout << i << " "; cout << "\n"; cout << "\n";

  int p = 1;
  vector<int> ans;

  for(int i = 1; i <= n-1; i++){
    if(__gcd(i, n) != 1)
      continue;

    p = (p*i)%n;
    ans.push_back(i);
  }

  cout << (p == 1 ? ans.size() : ans.size()-1) << "\n";
  for(auto i : ans){
    if(p != 1 && i == p) continue;
    cout << i << " ";
  }

  cout << "\n";
  
}