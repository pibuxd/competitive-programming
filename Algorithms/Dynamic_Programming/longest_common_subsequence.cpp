// * Longest Common Subsequence (LCS)
#include <bits/stdc++.h>
using namespace std;

string lcs(string a, string b){
  int as = a.size(), bs = b.size();
  vector<vector<int>> dp(as+1, vector<int>(bs+1));

  for(int i = 1; i <= as; i++)
    for(int j = 1; j <= bs; j++){
      if(a[i-1] == b[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  
  string ans = "";

  int i = as, j = bs;
  while(i > 0 && j > 0){
    if(dp[i-1][j] == dp[i][j-1]){
      ans += a[i-1];
      i--, j--;
    } else if(dp[i-1][j] > dp[i][j-1]){
      i--;
    } else{
      j--;
    }
  }

  /*
  cout << "\n";
  for(int i = 0; i <= as; i++){
    for(int j = 0; j <= bs; j++){
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  */
 
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){
  string a, b;
  cin >> a >> b;

  cout << lcs(a, b) << "\n";
}