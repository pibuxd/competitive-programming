// * RMQ
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define LOG 18

int n;
vector<vector<int>> v;
unordered_map<int, vector<int>> m;

void build(){
  for(int j = 1; j <= LOG; j++)
    for(int i = 1; i + (1 << (j-1)) <= n; i++)
      v[i][j] = min(v[i][j-1], v[i+(1<<(j-1))][j-1]);
}

int query(int a, int b){
  int len = b - a + 1;
  int j = floor(log2(len));
  return min(v[a][j], v[b-(1<<j)+1][j]);
}

int main(){
  fastio;
  cin >> n;
  v.resize(n+1, vector<int>(LOG+1));

  for(int i = 1; i <= n; i++){
    int _temp;
    cin >> _temp >> v[i][0];
    m[v[i][0]].push_back(i);
  }
  build();
  int ans = 0;

  for(auto it : m){
    auto f = it.first;
    auto a = it.second;
    
    for(int i = 1; i < a.size(); i++){
      if(query(a[i-1], a[i]) < f)
        ans++;
    }
    ans++;
  }

  cout << ans;
}