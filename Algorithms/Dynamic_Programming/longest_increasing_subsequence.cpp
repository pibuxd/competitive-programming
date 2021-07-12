// * Longest Increasing Subsequence (LIS)
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

// O(n^2)
int lis_slow(){
  vector<int> dp(n, 1);

  for(int i = 1; i < n; i++)
    for(int j = 0; j < i; j++){
      if(a[i] > a[j] && dp[j] + 1 > dp[i])
        dp[i] = dp[j] + 1; 
    }

  return *max_element(dp.begin(), dp.end());
}

// O(n*log(n))
int lis_fast(){
  return 0;
}

int main(){
  cin >> n;
  a.resize(n);

  for(int &x : a)
    cin >> x;
  
  cout << lis_slow() << "\n";
  cout << lis_fast() << "\n";
}