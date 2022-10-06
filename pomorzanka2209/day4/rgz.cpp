#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, k;
vector<vector<int>> G;

void 

int main(){
  fastio;
  cin >> n >> k;
  G.resize(n+1);

  for(int i = 1; i <= n; i++){
    while(true){
      int x; cin >> x;
      if(x == 0) break;
      G[i].push_back(x);
    }
  }
  
  for(int i = 1; i <= n; i++){

  }
}

