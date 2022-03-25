#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<vector<char>> a;
vector<int> h;

int max_area(){
  vector<int> l(m+1, 0), r(m+1, m+1);

  // first min on the left
  stack<int> s; 
  for(int i = m; i >= 1; i--){
    while(!s.empty() && h[s.top()] > h[i]){
      l[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }

  // first min on the right
  s = stack<int>(); 
  for(int i = 1; i <= m; i++){
    while(!s.empty() && h[s.top()] > h[i]){
      r[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }

  int ans = 0;
  for(int i = 1; i <= m; i++){
    int area = h[i] * (r[i]-1-l[i]-1+1);
    ans = max(ans, area);
  }

  return ans;
}

int main(){
  fastio;
  cin >> n >> m;

  h.resize(m+1);
  int mx = 0;

  for(int t = 1; t <= n; t++){
    for(int i = 1; i <= m; i++){
      char c; cin >> c;
      if(c == '.')
        h[i]++;
      else  
        h[i] = 0;
    }

    mx = max(mx, max_area());  
  }

  cout << mx;
}