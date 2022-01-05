#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

#define mid ((l+r)/2)
#define lv (2*v)
#define rv (2*v+1)

#define all(x) x.begin(), x.end()

int n, m, id; // id - ile roznych 
vector<int> a, u, k; // k - ile ciezarowek ma compressed km
vector<array<int, 2>> t; // t - {ile ciezarowek, sum km}
vector<array<int, 3>> in;
unordered_map<int, int> it; // it - original to compressed (km)

void compress(){
  sort(all(u));

  for(int i = 0; i < u.size(); i++)
    if(i == 0 || u[i] != u[i-1])
      it.insert(make_pair(u[i], ++id));
}

void upd(int v, int l, int r, int idx, int cnt, int km){
  if(l > idx || r < idx)
    return;
  if(l == r){
    t[v][0] = cnt;
    t[v][1] = cnt * km;
    return;
  }

  if(idx <= mid)
    upd(lv, l, mid, idx, cnt, km);
  else
    upd(rv, mid+1, r, idx, cnt, km);
  
  t[v][0] = t[lv][0] + t[rv][0];
  t[v][1] = t[lv][1] + t[rv][1];
}

array<int, 2> qry(int v, int l, int r, int L, int R){
  if(l > R || r < L)
    return {0, 0};
  if(L <= l && r <= R)
    return t[v];
  
  auto q1 = qry(lv, l, mid, L, R), q2 = qry(rv, mid+1, r, L, R);
  return {q1[0] + q2[0], q1[1] + q2[1]};
}

void upd(int idx, int cnt, int km){
  return upd(1, 1, id, idx, cnt, km);
}

auto qry(int l, int r){
  return qry(1, 1, id, l, r);
}

signed main(){
  fastio;
  cin >> n >> m;
  a.resize(n+1, 0);

  while(m--){
    char op; cin >> op;

    if(op == 'U'){
      int idx, km;
      cin >> idx >> km;
      in.push_back({0, idx, km});
      u.push_back(km);

    } else{
      int c, km; cin >> c >> km;
      in.push_back({1, c, km});
    }
  }

  id = 0;
  compress();

  t.resize(4*(id+1), {0, 0});
  k.resize(id+1, 0);

  for(auto i : in){
    if(i[0] == 0){
      int idx = i[1], km = i[2];

      k[it[a[idx]]]--;
      upd(it[a[idx]], k[it[a[idx]]], a[idx]);

      a[idx] = km;
      k[it[a[idx]]]++;
      upd(it[km], k[it[km]], km);

    } else{
      int c = i[1], km = i[2];

      int w = 0;
      auto x = lower_bound(all(u), km);          

      if(x == u.end()){
        w += qry(1, id)[1];

      } else if(!it[km]){
        if(it[*x]-1)
          w += qry(1, it[*x] - 1)[1];

        if(it[*x])
          w += qry(it[*x], id)[0] * km;

      } else{
        w += qry(1, it[*x])[1];
        if(it[*x] + 1 <= id)
          w += qry(it[*x] + 1, id)[0] * km;
      }

      if(w >= km*c) cout << "TAK\n";
      else cout << "NIE\n";
    }
  }
}