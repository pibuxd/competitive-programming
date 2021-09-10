#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<vector<int>> G;

int main(){
  fastio;
  cin >> n >> m;
  G.resize(n+1);

  set<pair<int, int>> edges;
  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    if(a < b)
      swap(a, b);
    
    if(!edges.count({a, b})){
      edges.insert({a, b});
      G[a].push_back(b);
    }

  }
}