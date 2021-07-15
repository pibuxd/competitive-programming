// * Count all possible paths in grid (matrix), but some squares are traps
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MOD = 1e9+7;
int n, num_of_paths;
vector<vector<int>> grid; // 0-cell, 1-trap

int count_paths(){
  if(grid[0][0] || grid[n-1][n-1]) return 0;
  vector<vector<int>> dp(n, vector<int>(n));
  dp[0][0] = 1;

  for(int i = 1; i < n; i++){
    if(!grid[0][i])
      dp[0][i] = dp[0][i-1];
    if(!grid[i][0])
      dp[i][0] = dp[i-1][0];
  }

  for(int i = 1; i < n; i++)
    for(int j = 1; j < n; j++){
      if(!grid[i][j])
        dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % MOD;
    }

  return dp[n-1][n-1];
}

int main(){
  fastio;
  cin >> n;
  grid.resize(n, vector<int>(n));

  for(vector<int> &v : grid)
    for(int &i : v){
      char c;
      cin >> c;
      if(c == '*')
        i = true;
    }

  int num_of_paths = 0;
  num_of_paths = count_paths();
  cout << num_of_paths;
}