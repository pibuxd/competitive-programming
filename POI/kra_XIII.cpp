// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF (int)(1e9)

int n, m;
vector<int> p;
vector<int> d;

int main(){
  fastio;
  cin >> n >> m;
  p.resize(n+1);
  d.resize(n+1, 0);

  p[0] = INF;
  for(int i = 1; i <= n; i++){
    int x; cin >> x;
    p[i] = min(p[i-1], x);
  }

  int pos = n+1;

  while(m-- && pos > 0){
    int v; cin >> v;

    while(p[pos-1] < v && pos > 0){
      pos--;
    }
    pos--;
  }

  cout << pos;
}