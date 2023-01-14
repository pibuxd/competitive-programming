#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<vector<array<int, 3>>> G;
vector<vector<int>> A;
vector<bool> vis;
vector<vector<array<int, 3>>::iterator> IT;

void dfs(int v, vector<int> &curr){ // return koncowy wierzch
  curr.push_back(v);
  vis[v] = true;

  while(IT[v] != G[v].end()){
    auto &[x, b, p] = *(IT[v]++);
    if(b){
      b = 0;
      G[x][p][1] = 0;
      
      if(vis[x]){
        vector<int> toadd({x});
        A.push_back(toadd);
        while(!curr.empty() && curr.back() != x){
          A.back().push_back(curr.back());
          vis[curr.back()] = false;
          curr.pop_back();
        }
        A.back().push_back(x);
        vis[x] = false;

      } else{
        vis[v] = true;
        dfs(x, curr);
      }
      if(curr.back() != v)
        return;
    }
  }
}

int main(){
  fastio;
  cin >> n >> m;
  G.resize(n+1);
  IT.resize(n+1);

  for(int i = 1; i <= m; i++){
    int a, b, s, t; cin >> a >> b >> s >> t;
    if(s != t){
      G[a].push_back({b, 1, (int)G[b].size()});
      G[b].push_back({a, 1, (int)G[a].size()-1});
    }
  }
  
  for(int i = 1; i <= n; i++)
    IT[i] = G[i].begin();
  
  for(int i = 1; i <= n; i++){
    if(G[i].size() & 1){
      cout << "NIE\n";
      return 0;
    }
  }
    
  vis.resize(n+1);

  for(int i = 1; i <= n; i++){
    vector<int> c({i});
    dfs(i, c);
  }

  cout << A.size() << "\n";
  for(auto &a : A){
    cout << a.size()-1 << " ";
    for(int i : a)
      cout << i << " ";
    cout << "\n";
  }
}
