#include "bits/stdc++.h"
using namespace std;

const int MXN = 1e5;
int n, dlg, minimum = MXN+1, start, ending;
vector<vector<int>> G(MXN+1);
vector<bool> visited(MXN+1);
vector<int> parent;
vector<int> rodz;

void readG(){
  cin >> n;

  for(int i = 1, a, x; i <= n; i++) {
    cin >> x;
    while(x--) {
      cin >> a;
      G[i].push_back(a);
    }
  }
}

void printPath(int x, int y){
  vector<int> ans;
  while(y != x){
    ans.push_back(y);
    y = parent[y];
  }
  ans.push_back(x);

  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size()-1; i++)
    cout << ans[i] << ' ';
  cout << ans[ans.size()-1] << '\n';
}

void visit(int v){
  visited[v] = true;
  dlg++;

  for(int x : G[v]) {
    if(!visited[x]) {
      rodz[x] = v;
      visit(x);
    } else {
      if(dlg < minimum){
        parent = rodz;
        minimum = dlg;
        start = x;
        ending = v;
        //return;
      }
    }
  }
}

void findCycle(){
  for(int v = 1; v <= n; v++)
    if(!visited[v]){
      visited.resize(MXN+1);
      dlg = 0;
      rodz.resize(MXN+1);
      visit(v);
    }
  
  printPath(start, ending);
}

int main(){
  readG();
  findCycle();
}
