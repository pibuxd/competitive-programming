// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF (1e9)

struct hshfn{
  size_t operator()(const pair<int, int> &p) const {
    auto hash1 = hash<int>{}(p.first);
    auto hash2 = hash<int>{}(p.second);
    return hash1 ^ hash2;
  }
};

int n, m, q;
vector<vector<int>> G;
vector<int> p, np;

void bfs(int st){
  queue<array<int, 2>> q;
  q.push({st, 0});

  while(!q.empty()){
    int v = q.front()[0];
    int w = q.front()[1];
    q.pop();

    for(int x : G[v]){
      if(p[x] == INF && (w + 1) % 2 == 0){
        p[x] = w + 1;
        q.push({x, w+1});

      } else if(np[x] == INF && (w + 1) % 2 != 0){
        np[x] = w + 1;
        q.push({x, w+1});
      }
    }
  }
}

int main(){
  fastio;
  cin >> n >> m >> q;

  G.resize(n+1);
  unordered_set<pair<int, int>, hshfn> S;

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;

    if(!S.count({a, b}) || !S.count({b, a})){
      G[a].push_back(b);
      G[b].push_back(a);
      S.insert({a, b});
    }
  }

  vector<array<int, 4>> in;
  in.push_back({0,0,0,0});

  for(int i = 1; i <= q; i++){
    int s, t, d;
    cin >> s >> t >> d;
    in.push_back({s, t, d, i});
  }
  sort(in.begin(), in.end());

  vector<bool> ans(q+1);

  for(int i = 1, lasts = 0; i <= q; i++){
    int s, t, d, id;
    s = in[i][0], t = in[i][1], d = in[i][2], id = in[i][3];

    if(lasts < s){
      p.assign(n+1, INF); // parzyste
      np.assign(n+1, INF); // nieparzyste
      bfs(s);
    }

    if(d % 2 == 0){
      // cout << p[s][t] << " ";
      if(p[t] <= d)
        ans[id] = 1;
      else
        ans[id] = 0;
      
    } else{
      // cout << np[s][t] << " ";
      if(np[t] <= d)
        ans[id] = 1;
      else  
        ans[id] = 0;
    }

    lasts = s;
  }

  for(int i = 1; i <= q; i++)
    cout << (ans[i] == 1 ? "TAK" : "NIE") << "\n";

}