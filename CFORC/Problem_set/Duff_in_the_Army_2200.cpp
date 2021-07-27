#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

const int LOGN = 18;
int n, m, q;
vector<vector<int>> G, c, up;
vector<vector<vector<int>>> path;
vector<int> depth;

vector<int> _merge(const vector<int> &x, const vector<int> &y){
  vector<int> z(10);
  int xi = 0, yi = 0;
  for(int i = 0; i < z.size(); i++){
    while(xi < x.size() && !x[xi]) xi++;
    while(yi < y.size() && !y[yi]) yi++;

    if(xi < x.size() && yi < y.size()){
      if(x[xi] <= y[yi])
        z[i] = x[xi], xi++;
      else if(x[xi] > y[yi])
        z[i] = y[yi], yi++;
    }
    else if(xi < x.size())
      z[i] = x[xi], xi++;
    else if(yi < y.size())
      z[i] = y[yi], yi++;
    else
      return z;
  }
  return z;
}

void dfs(int v, int p){
  depth[v] = depth[p] + 1;
  up[v][0] = p;
  path[v][0] = _merge(c[v], path[v][0]);

  for(int i = 1; i <= LOGN; i++){
    up[v][i] = up[up[v][i-1]][i-1];
    path[v][i] = _merge(path[up[v][i-1]][i-1], path[v][i-1]);
  }

  for(int x : G[v])
    if(x != p)
      dfs(x, v);
}
 
vector<int> lca(int a, int b){
  vector<int> ans_a(10), ans_b(10), ans(10);

  if(depth[a] < depth[b])
    swap(a, b); // depth[a] > depth[b]
  int k = depth[a] - depth[b];
 
  for(int i = 0; i <= LOGN; i++)
    if((k >> i) & 1)
      ans_a = _merge(path[a][i], ans_a), a = up[a][i];

  if(a == b){
    // ans_a = _merge(ans_a, c[a]);
    ans = _merge(ans_a, c[b]);
    return ans;
  }
  
  for(int i = LOGN-1; i >= 0; i--)
    if(up[a][i] != up[b][i]){
      ans_a = _merge(path[a][i], ans_a);
      ans_b = _merge(path[b][i], ans_b);
      a = up[a][i], b = up[b][i];
    }
    
  ans = _merge(ans_a, ans_b);
  ans = _merge(path[a][0], ans);
  ans = _merge(path[b][0], ans);
  ans = _merge(c[up[a][0]], ans);
  return ans;
}
 
int main(){
  fastio;
  cin >> n >> m >> q;
  G.resize(n+1);
  c.resize(n+1);
  depth.resize(n+1);
  up.resize(n+1, vector<int>(LOGN+1));
  path.resize(n+1, vector<vector<int>>(LOGN+1, vector<int>(10)));
 
  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i = 1; i <= m; i++){
    int a; cin >> a;
    c[a].push_back(i);
  }
  for(int i = 1; i <= n; i++)
    sort(all(c[i]));
 
  dfs(1, 1);
  cout << "\n";
  while(q--){
    int x, y, a; cin >> x >> y >> a;
    vector<int> ans, temp;
    temp = lca(x, y);
    //sort(all(ans));
    for(int i : temp){
      if(i > 0)
        ans.push_back(i);
      else
        break;
    }
    a = min(a, (int)ans.size());
    cout << a << " ";
    for(int i = 0; i < a; i++)
      cout << ans[i] << " ";
    cout << "\n";
  }
}
