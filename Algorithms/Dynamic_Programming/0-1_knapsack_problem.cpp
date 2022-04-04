// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * 0-1 Knapsack problem
// * buy at most number of pages for the maximum amount
// * 0-1 means that we can pick the complete item or don’t pick it
// task link -> https://cses.fi/problemset/task/1158
#include <bits/stdc++.h>
using namespace std;

struct Book{
  int price, pages;
};

int main(){
  int n, x; // n - number of books, x - maximum amount to be spent
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