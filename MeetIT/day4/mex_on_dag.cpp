#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<vector<array<int, 2>>> G;
vector<vector<bool>> dp;
vector<array<int, 2>> edges;

void dfs(int v, int weight){
  for(auto x : G[v]){
    dp[weight][x[1]] = true;
    dfs(x[0], weight);
  }
}

void dfs2(int v, int &id, vector<vector<int>> &__G, stack<int> &st,
          vector<bool> &on_st, vector<int> &ids, vector<int> &low){
  st.push(v);
  on_st[v] = true;
  ids[v] = low[v] = id++;

  for(int x : __G[v]){
    if(!ids[x])
      dfs2(x, id, __G, st, on_st, ids, low);
    if(on_st[x])
      low[v] = min(low[v], low[x]);
  }

  if(ids[v] == low[v]) // starting point of SCC
    for(int node = st.top();; node = st.top()){
      st.pop();
      on_st[node] = false;
      low[node] = ids[v];
      if(node == v)
        break;
    }
}

bool check(int val){
  vector<vector<int>> sat(2*n);

  for(int i = 0; i <= 2*val+1; i++){
    for(int j = 0; j <= 2*val+1; j++){
      if(!dp[i][j] && i != j+1 && i != j-1){
        cout << "i = " << i << ", j = " << j << "\n";
        sat[i].push_back(j);
      }
    }
  }
  
  stack<int> st;
  vector<int> ids(2*n), low(2*n);
  vector<bool> on_st(2*n);
  int id = 0;

  for(int i = 0; i <= 2*val+1; i++)
    if(!ids[i]){
      st = stack<int>();
      on_st.resize(2*n);
      dfs2(i, id, sat, st, on_st, ids, low);
    }
  
  for(int i = 0; i <= val; i++){
    if(low[2*i] == low[2*i+1]){
      cout << "I: " << i << " " << low[2*i] << ", " << low[2*i+1];
      return false;
    }
  }

  return true;
}

int main(){
  fastio;
  cin >> n;
  G.resize(n+1);
  edges.resize(2*n);
  dp.resize(2*n, vector<bool>(2*n));

  for(int i = 0; i <= 2*n-1; i++){
    dp[i][i] = true;
  }

  for(int i = 0; i <= 2*n-1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back({b, i});
    edges[i] = {a, b};
  }

  for(int i = 0; i <= 2*n-1; i++){
    dfs(edges[i][1], i);
  }

  for(int i = 0; i <= 2*n-1; i++){
    for(int j = 0; j <= 2*n-1; j++)
      if(dp[i][j] || dp[j][i])
        dp[i][j] = dp[j][i] = true;
  }

  for(int i = 0; i <= 2*n-1; i++){
    cout << "\n" << i << ":  ";
    for(int j = 0; j <= 2*n-1; j++)
      cout << dp[i][j] << " ";
  }

  // int l = 0, r = 2*n-1, ans = 0;
  // while(l <= r){
  //   int m = (l+r)/2;
  //   bool ok = check(m);
  //   if(ok){
  //     ans = m;
  //     l = m+1;
  //   }
  //   else{
  //     r = m-1;
  //   }
  // }
  cout << "\n\n";
  int i = 3;
    if(check(i))
      cout << i << " ";

  // int y = 0;
  // if(check(y))
  //   cout << y;

  // cout << "\n" << ans;
}