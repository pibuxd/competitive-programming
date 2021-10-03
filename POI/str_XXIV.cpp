#include <bits/stdc++.h>
using namespace std;

int n, parts;
vector<vector<int>> G;
vector<bool> blocked;

void initData(){
  cin >> n;
  
  parts = 0;
  G = vector<vector<int>>(n+1);
  blocked = vector<bool>(n+1);

  for(int i = 1, a, b; i < n; i++){
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}

int numberOfParts(int node){
  int v = abs(node);
  int wolne = 0;

  if(node > 0){
    blocked[v] = true;

    if(G[v].size() == 1){
      if(blocked[G[v][0]]){
        parts--;
      }

      return parts;
    }

    for(int x : G[v]){
      if(!blocked[x]){
        wolne++;
        parts++;
      }
    }

    if(wolne == 0){
      parts--;
    }

  } else{
    blocked[v] = false;

    if(G[v].size() == 1){
      if(blocked[G[v][0]]){
        parts++;
      }

      return parts;
    }

    for(int x : G[v]){
      if(!blocked[x]){
        wolne++;
        parts--;
      }
    }

    if(wolne == 0){
      parts++;
    }
  }

  return parts;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  initData();

  int m, v;
  cin >> m;

  cin >> v;
  parts = numberOfParts(v);
  m--;

  if(parts == 0){
    parts = 1;
  }

  cout << parts << '\n';

  while(m--){
    cin >> v;
    cout << numberOfParts(v) << '\n';
  }
}