// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * DP on tree + find centroid
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int n, sum;
vector<vector<int>> G;
vector<int> pnajd, dist, ile, wielk;
// ile[i] and wielk[i] are size of subtree i, but they concern another root

void dfs(int v, int p){
  for(int x : G[v]){
    if(x == p) continue;

    dist[x] = dist[v] + 1;
    sum += dist[x];

    dfs(x, v);
    pnajd[v] = max(pnajd[v], pnajd[x] + 1);
    wielk[v] += wielk[x];
  }
}

void _dfs(int v, int p){
  for(int x : G[v]){
    if(x == p) continue;
    _dfs(x, v);
    ile[v] += ile[x]; 
  }
}

int find_centroid(int v, int p){
  for(int x : G[v]){
    if(x == p) continue;
    
    if(ile[x] > n/2){
      ile[v] -= ile[x];
      ile[x] = n;
      return find_centroid(x, v);
    }
  }

  return v;
}

array<int, 2> cen(){
  _dfs(1, 0);
  int c1 = find_centroid(1, 0);

  int c2 = [c1]()->int{
    for(int v : G[c1]){
      if(ile[c1]-ile[v] == n/2 && ile[v] == n/2)
        return v;  
    }
    return -1;
  }();

  // cout << "\nCEN: "  << c1 << ", " << c2 << "\n";
  return {c1, c2};
}

signed main(){
  fastio;
  cin >> n;
  G.resize(n+1);

  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  if(n == 1){
    cout << "0";
    return 0;
  }

  ile.assign(n+1, 1);
  array<int, 2> cent = cen();

  for(int i = 1; i <= n; i++){
    if(i != cent[0] && i != cent[1]){ cout << "-1\n"; continue; }

    sum = 0;
    dist.assign(n+1, 0);
    pnajd.assign(n+1, 0);
    wielk.assign(n+1, 1);
    dfs(i, 0);

    sum *= 2;
    if(cent[1] == -1)
      sum -= pnajd[i];
    else{
      array<int, 2> it = {0, 0};
      for(int x : G[i])
        it = max(it, {wielk[x], x});
      sum -= pnajd[it[1]]+1;
    }

    cout << sum << "\n";
  }
}