// 1. Create SCC
// 2. Make DAG - each node is one SCC and Tarjan's algo
//    will make topologial order automatically
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// 1:
long long _n; // number of vertices in input
long long m, id;
vector<vector<long long>> G;
vector<long long> low, ids, coins;
vector<bool> on_st;
stack<long long> st;

// 2:
long long n; // number of SCC in graph
vector<vector<long long>> dag;
vector<long long> dist, weight;

void dfs(long long v){
  st.push(v);
  on_st[v] = true;
  low[v] = ids[v] = id++;

  for(long long x : G[v]){
    if(!ids[x])
      dfs(x);
    if(on_st[x])
      low[v] = min(low[v], low[x]);
  }

  if(ids[v] == low[v])
    for(long long node = st.top();; node = st.top()){
      st.pop();
      on_st[node] = false;
      low[node] = ids[v];
      if(node == v)
        break;
    }
}

int main(){
  fastio;
  cin >> _n >> m;
  low = ids = coins = vector<long long>(_n+1);
  G = vector<vector<long long>>(_n+1);

  for(long long i = 1; i <= _n; i++)
    cin >> coins[i];
  for(long long i = 1; i <= m; i++){
    long long a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  id = 0;
  for(long long i = 1; i <= _n; i++)
    if(!ids[i]){
      on_st = vector<bool>(_n+1);
      st = stack<long long>();
      dfs(i);
    }

  map<long long, long long> ans;
  vector<long long> lows;
  n = 0;
  long long temp = 1;
  for(long long i = 1; i <= _n; i++)
    if(!ans[low[i]]){
      ans[low[i]] = temp, temp++, n++;
      lows.push_back(low[i]);
  }
  
  weight = dist = vector<long long>(_n+1);
  dag = vector<vector<long long>>(_n+1);
  
  for(long long i = 1; i <= _n; i++)
    weight[low[i]] += coins[i];
  
  vector<vector<bool>> visited(_n+1, vector<bool>(_n+1));
  for(long long i = 1; i <= _n; i++)
    for(long long x : G[i])
      if(!visited[low[i]][x] && low[x] != low[i]){
        visited[low[i]][x] = true;
        dag[low[i]].push_back(low[x]);
      }
  /*
  cout << "\n";
  for(long long l : lows) cout << l << " ";
  cout << "\n\n";
  for(long long l : lows){
    cout << l << ": ";
    for(long long x : dag[l])
      cout << x << " ";
    cout << "\n";
  }
  cout << "\n";

  for(long long l : lows)
    cout << weight[l] << " ";
  cout << "\n";
  */
  sort(lows.begin(), lows.end());
  for(long long l : lows)
    dist[l] = weight[l];
  for(long long l : lows)
    for(long long x : dag[l]){
      dist[x] = max(dist[x], dist[l] + weight[x]);
    }

  cout << *max_element(dist.begin(), dist.end());
}