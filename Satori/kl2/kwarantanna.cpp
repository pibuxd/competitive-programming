#include "bits/stdc++.h"
using namespace std;

// Tarjan's SCC

const int MXN = 1e5;
int n, id;
bitset<MXN+1> onStack;
stack<int> S;

void readG(vector<vector<int>> &G){
  for(int i = 1, a, x; i <= n; i++) {
    cin >> x;
    while(x--) {
      cin >> a;
      G[i].push_back(a);
    }
  }
}

void dfs(int x, vector<int> &visited, vector<int> &low, vector<vector<int>> &G){
  S.push(x);
  onStack[x] = true;
  
  visited[x] = low[x] = id++;

  for(int v : G[x]){
    if(!visited[v]){
      dfs(v, visited, low, G);
    }
    if(onStack[v]){
      low[x] = min(low[v], low[x]);
    }
  }

  if(visited[x] == low[x]){
    for(int node = S.top(); ; node = S.top()){
      S.pop();
      onStack[node] = false;
      low[node] = visited[x];

      //cout << node << "\n";
      if(node == x){
        break;
      }
    }
  }
}

void createSCC(vector<vector<int>> &G, vector<int> &low){
  vector<int> visited(n+1);
  id = 1;

  for(int i = 1; i <= n; i++){
    if(!visited[i]){
      S = stack<int>();
      onStack.reset();

      dfs(i, visited, low, G);
    }
  }
}

void minCorrectSCC(vector<vector<int>> &G, vector<int> &low){
  vector<int> teamSize(n+1);

  for(int i = 1; i <= n; i++){
    for(int g : G[i]){
      if(low[g] != low[i]){
        teamSize[low[i]] = -1;
        goto nxt;
      }
    }
    
    teamSize[low[i]]++;
    nxt:;
  }

  int minimum = n+1, it;
  for(int i = 1; i <= n; i++){
    if(teamSize[i] < minimum && teamSize[i] > 0){
      minimum = teamSize[i];
      it = i;
    }
  }

  cout << minimum << '\n';
  for(int i = 1; i <= n; i++){
    if(low[i] == it){
      cout << i << ' ';
    }
  }
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;

  while(t--){
    cin >> n;
    vector<vector<int>> G(n+1);
    vector<int> low(n+1);
    readG(G);
    createSCC(G, low);
    /*
    cout << '\n';
    for(int i = 1; i <= n; i++){
      cout << low[i] << ' ';
    }
    cout << "\n\n";
    */
    minCorrectSCC(G, low);
    cout << '\n';
  }
}