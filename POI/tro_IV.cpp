#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;

int main(){
  fastio;
  cin >> n >> m;
  int X = (n*(n-1)*(n-2)) / 6;

  vector<int> a(n+1);

  for(int i = 1; i <= m; i++){
    int v, u;
    cin >> v >> u;
    a[v]++, a[u]++;
  }

  for(int i = 1; i <= n; i++){
    X -= (a[i] * (n-1-a[i]) ) / 2;
  }

  cout << X;
}