#include<bits/stdc++.h>
using namespace std;

#define PB push_back

int lpokoi, zasieg, pojemn;
vector<vector<int>> G;
vector<bool> zabezpieczony;

void readGraph(){
  cin >> lpokoi >> zasieg >> pojemn;
  G.resize(lpokoi+1);
  for(int i = 0; i < lpokoi - 1; i++){
    int a, b; cin >> a >> b;
    G[a].PB(b); G[b].PB(a);
  }
}

void dfs(int n, int &gasnice){
  zabezpieczony[n] = true;

  for(int x : G[n]){
    if(!zabezpieczony[x]){


    dfs(x, gasnice);
    }
  }
}

int ileGasnic(){
  zabezpieczony.resize(lpokoi+1);
  int gasnice = 0;

  for(int i = 1; i <= lpokoi; i++)
    if(!zabezpieczony[i])
      dfs(i, gasnice);

  return gasnice;
}

int main(){ //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  readGraph();
  cout << ileGasnic();
  return 0;
}
