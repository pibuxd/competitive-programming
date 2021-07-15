// * 0-1 Knapsack problem
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Book{
  int price, pages;
};

int main(){
  fastio;
  int n, x;
  cin >> n >> x;

  vector<Book> books(n+1); 
  for(int i = 1; i <= n; i++) cin >> books[i].price;
  for(int i = 1; i <= n; i++) cin >> books[i].pages;

  vector<vector<int>> dp(n+1, vector<int>(x+1));
  
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= x; j++){
      if(books[i].price <= j)
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-books[i].price] + books[i].pages);
      else
        dp[i][j] = dp[i-1][j];
    }

  cout << dp[n][x];  
}