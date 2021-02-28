#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MXLOGN = 19;

class Tree {
public:
  int n;
  vector<vector<int>> G;
  vector<vector<int>> jumps;
  vector<int> level;
  vector<int> parents;

  Tree(int _n){
    n = _n;
    G.resize(n+1);
    level.resize(n+1);
    jumps.resize(n+1, vector<int>(MXLOGN+1));
  }

  void push(int a, int b){
    G[a].push_back(b);
  }

  void dfs(int x, int parent){
    jumps[x][0] = parent;
    level[x] = level[parent] + 1;

    for(int v : G[x]){
      if(v != parent){
        dfs(v, x);
      }
    }
  }

  void generate(){
    for(int i = 1; i <= n; i++){
      if(jumps[i][0] == 0){
        dfs(i, i);
      }
    }

    for(int j = 1; j <= MXLOGN; j++){
      for(int i = 1; i <= n; i++){
        jumps[i][j] = jumps[jumps[i][j-1]][j-1];
      }
    }
  }

  int lca(int x, int y){
    if(level[x] < level[y]){
      swap(x, y);
    }

    for(int i = MXLOGN; i >= 0; i--){
      if(level[x] - (1<<i) >= level[y]){
        x = jumps[x][i];
      }
    }

    if(x == y){
      return x;
    }

    for(int i = MXLOGN; i >= 0; i--){
      if(jumps[x][i] != jumps[y][i]){
        x = jumps[x][i];
        y = jumps[y][i];
      }
    }

    return jumps[x][0];
  }

  int maxEdge(int a, int b){
    int ancestor = lca(a, b);
    return ancestor;

  }
};

int main(){
  fastio;
  int n, m;
  cin >> n >> m;

  Tree tree(n);

  for(int i = 1, a; i < n; i++){
    cin >> a;
    tree.push(i, a);
  }

  tree.generate();

  for(int a, b; m--;){
    cin >> a >> b;

    cout << tree.maxEdge(a, b) << '\n'; 
    
  }
}