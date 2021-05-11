#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n, m;
  cin >> n >> m;

  vector<vector<int>> G(n+1);
  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  vector<pair<int, int>> topics(n+1);
  for(int i = 1; i <= n; i++){
    cin >> topics[i].first;
    topics[i].second = i;
  }
  sort(topics.begin(), topics.end());
  vector<int> ans;
  vector<int> val;
  
  for(int i = 1; i <= n; i++){
    int x = topics[i].first;
    int v = topics[i].second;
    
  }
  

  for(int x : ans){
    cout << x << "\n";
  }
}