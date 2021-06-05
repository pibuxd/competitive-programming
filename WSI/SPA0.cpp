#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> a;
vector<bool> is_start, visited, _visited;

int dfs(int v, int dist){
  visited[v] = _visited[v] = true;

  if(a[v] == v || _visited[a[v]]){
    return dist;
  }

  return dfs(a[v], dist + 1);
}

int dfs2(int v, int dist){
  visited[v] = true;

  if(a[v] == v || visited[a[v]]){
    return dist;
  }

  return dfs(a[v], dist + 1);
}

int main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  is_start.resize(n+1, true);
  visited.resize(n+1);
  _visited.resize(n+1);

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    is_start[a[i]] = false;
  }

   int maximum = 0;

  for(int i = 1; i <= n; i++){
    if(is_start[i]){
      for(int i = 1; i <= n; i++) _visited[i] = false;
      
      int dist = dfs(i, 0);
      //cout << i << ": " << dist << "\n";
      maximum = max(maximum, dist);
    }
  }

  for(int i = 1; i <= n; i++){
    if(!visited[i]){
      int dist = dfs2(i, 0);
      //cout << i << ": " << dist << "\n";
      maximum = max(maximum, dist);
    }
  }

  cout << maximum + 1;
}