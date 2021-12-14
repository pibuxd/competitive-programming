#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

int n;

void bfs(vector<vector<int>> &G, vector<ll> &dist, vector<bool> &end){
  queue<int> Q;
  vector<bool> visited(n+1);
  Q.push(1);
  visited[1] = true;
  
  while(!Q.empty()){
    int v = Q.front();
    Q.pop();
    bool is_end = true;

    for(int x : G[v]){
      if(!visited[x]){
        visited[x] = true;
        Q.push(x);
        dist[x] = dist[v] + 1;
        is_end = false;
      }
    }

    if(is_end) end[v] = true;
  }
}

int main(){
  fastio;
  cin >> n;

  vector<vector<int>> G(n+1);
  vector<ll> dist(n+1);
  vector<bool> end(n+1);

  for(int i = 1; i <= n - 1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  bfs(G, dist, end);

  double average_dist = 0;
  ll endings = 0;

  for(int i = 1; i <= n; i++){
    if(end[i]){
      endings++;
      average_dist += dist[i];
    }
  }

  average_dist /= endings;
  cout << average_dist;
}