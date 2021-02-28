#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Edge { int node; char ul; };

struct Graph {
  int n;
  vector<vector<Edge>> G;
  vector<int> ile;
  
  Graph(int _n){
    n = _n;
    G.resize(n+1);
  }

  void push(int a, int b, char ul){
    G[a].push_back({b, ul});
    G[b].push_back({a, ul});
  }

  int findCentroid(int x){

  }

  void genLongestTemplates(){
    for(int i = 1; i <= n; i++){
      if(G[i].size() == )
    }
  }
};

int main(){
  //fastio;
  int n;
  cin >> n;
  Graph G(n);

  char ul;
  for(int i = 1, a, b; i < n; i++){
    cin >> a >> b >> ul;
    G.push(a, b, ul);
  }

  G.genLongestTemplates(){

  }
}