#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n;
  vector<int> p;
  cin >> n;
  p.assign(2*n+1, 0);

  for(int i = 1; i <= 2*n; i++)
    cin >> p[i];

  vector<int> onstack(n+1, 0), ans;
  stack<int> s, d;
  for(int i = 2*n; i >= 1; i--)
    s.push(p[i]);

  while(!s.empty()){
    int st = s.top();
    s.pop();

    if(onstack[st] == 0)
      onstack[st] = 1, d.push(st);
    else{
      int dt = d.top();
      d.pop();
      onstack[dt] = 0;

      if(dt != st)
        ans.push_back(d.size()+1),
        s.push(dt),
        s.push(st);
    }
  }
  
  cout << ans.size() << "\n";
  for(int a : ans) cout << a << "\n";
}