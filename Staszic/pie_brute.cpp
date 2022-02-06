#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int m, mn;
vector<array<int, 2>> in;
vector<int> ans;

void foo(vector<bool> vis, vector<int> a, int x, int y, int did){
  if(x != -1 && y != -1){
    if(a.empty() || a.back() != x)
      a.push_back(x);
    a.push_back(y);
  }

  for(int i = 1; i <= m; i++){
    if(!vis[i]){
      vis[i] = true;
      foo(vis, a, in[i][0], in[i][1], did+1);
      vis[i] = false;
    }
  }

  if(did == m && a.size() < mn){
    ans = a;
    mn = a.size();
  }
}

int main(){
  fastio;
  cin >> m;
  mn = 1e7;

  in.resize(m+1);

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    in[i] = {a, b};
  }

  foo(vector<bool>(m+1, false), vector<int>(), -1, -1, 0);

  cout << ans.size() << "\n";
  for(int i : ans) cout << i << " ";
}