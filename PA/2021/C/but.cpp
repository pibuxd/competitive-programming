// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF INT_MAX

array<int, 3> start, mx;
vector<int> w;

void calc(){
  map<array<int, 3>, int> d;
  queue<array<int, 3>> q;
  
  q.push(start);
  d[start] = 1;

  while(!q.empty()){ // BFS
    auto x = q.front();
    q.pop();

    int depth = d[x];
    w[x[0]] = min(w[x[0]], depth);
    w[x[1]] = min(w[x[1]], depth);
    w[x[2]] = min(w[x[2]], depth);

    for(int i = 0; i <= 2; i++)
      for(int j = 0; j <= 2; j++){ // i -> j
        if(i == j) continue;
        
        auto y = x;
        int _a = min(x[i], mx[j] - x[j]);
        y[i] -= _a, y[j] += _a;

        if(!d[y] && y != start){
          d[y] = d[x] + 1;
          q.push(y);
        }
      }
  }
}

int main(){
  fastio;
  cin >> mx[0] >> mx[1] >> mx[2] >>
  start[0] >> start[1] >> start[2];

  w.resize(mx[2]+1, INF);

  calc();

  for(int i : w)
    cout << ((i == INF) ? -1 : i-1) << " ";
}