#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> x, y, l;

int main(){
  fastio;
  cin >> n;
  x = y = l = vector<int>(n+1, 0);
  
  for(int i = 1; i <= n; i++)
    cin >> x[i] >> y[i];

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

  for(int i = n; i >= 1; i--){
    while(!Q.empty() && Q.top().first < x[i]){
      l[Q.top().second] = i;
      Q.pop();
    }
    Q.push({y[i], i});
  }
  for(int i = 1; i <= n; i++)
    l[i] = max(l[i-1], l[i]);
  
  int mx = 0;
  for(int i = 1; i <= n; i++)
    mx = max(mx, i-l[i]);

  cout << mx << "\n";
}
