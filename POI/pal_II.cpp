#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<char> a;
vector<vector<int>> G;
vector<bool> vis;
vector<int> distmn, distmx, topo, parmn, parmx, mnp, mxp;

void dfs(int v){
  vis[v] = true;

  for(int x : G[v])
    if(!vis[x])
      dfs(x);
  
  topo.push_back(v);
}

void mn(int v){
  if(parmn[v] != -1)
    mn(parmn[v]);
  mnp.push_back(v);
}

void mx(int v){
  if(parmx[v] != -1)
    mx(parmx[v]);
  mxp.push_back(v);
}

void printstr(int l, int r){
  while(l <= r){ 
    cout << a[l];
    l++;
  }
}

int main(){
  fastio;
  string _s;
  cin >> _s;
  n = _s.size();
  a.resize(n+1);
  vis.resize(n+2);
  distmn.resize(n+2, 200);
  distmx.resize(n+2, 0);
  parmn.resize(n+2, -1);
  parmx.resize(n+2, -1);

  for(int i = 1; i <= n; i++)
    a[i] = _s[i-1];
  G.resize(n+3);

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(!(i-j >= 0 && i+j <= n)) continue;

      if(a[i-j+1] == a[i+j]){
        G[i-j].push_back(i+j);
        // cout << i-j << " -> " << i+j << "\n";
      }
      else
        break;
    }
  }

  dfs(0);
  reverse(topo.begin(), topo.end());
  distmn[topo[0]] = 0;

  for(int i : topo){
    // cout << i << " ";
    for(int x : G[i]){
      if(distmn[x] > distmn[i] + 1){
        distmn[x] = distmn[i] + 1;
        parmn[x] = i;
      }
      if(distmx[x] < distmx[i] + 1){
        distmx[x] = distmx[i] + 1;
        parmx[x] = i;
      }
    }
  }

  if(distmn[n] == 200){
    cout << "NIE";
    return 0;
  }
  // cout << "\nMN: ";
  mn(n);
  for(int i = 0; i < mnp.size()-1; i++){
    printstr(mnp[i]+1, mnp[i+1]);
    cout << " ";
  }
  // cout << "\nMX: ";
  cout << "\n";
  mx(n);
  for(int i = 0; i < mxp.size()-1; i++){
    printstr(mxp[i]+1, mxp[i+1]);
    cout << " ";
  }
  // cout << "\n" << distmn[n] << "\n" << distmx[n];
}