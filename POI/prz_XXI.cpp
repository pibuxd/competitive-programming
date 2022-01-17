// * Greedy
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define INF (int)(1e9)

int n, k, m, l, endk, startm, startl, prz;
vector<int> c, x, y, ne, pr, _ne, _pr, a, _a;
vector<vector<int>> v, _v;
vector<bool> vis;

int pierw(int i){
  return !v[i].empty() ? v[i][0] : -1;
}

int ost(int i){
  return !_v[i].empty() ? _v[i][0] : -1;
}

void p0(vector<vector<int>> &__v, vector<int> &__ne, vector<int> &__pr, vector<int> &__x, int __m, int il){
  for(int j = 1; j <= __m-1; j++){
    auto it = __v[__x[j+1]].begin();
    auto e = __v[__x[j+1]].end();
    int las = 0;

    for(int i : __v[__x[j]]){
      while((*it) * il < i * il && it != e){
        it++;
        if(it != e){
          __ne[las] = *it;
          __pr[*it] = las;
        }
      }
      if(it == e) break;
      __ne[i] = *it;
      __pr[*it] = i;
      las = i;
    }

    // cout <<( it == e )<< ": ";
    while(it != e){
    //   cout << *it << " ";
      __pr[*it] = las;
      it++;
    }
  }
}

void p1(int endi, int node, vector<vector<int>> &__v, vector<int> &__ne, vector<int> &__pr, vector<int> &__a, int __start){
  if(vis[node]) return;
  vis[node] = true;

  if(c[node] == __start)
    __a[node] = endi;
  if(c[node] != __start && __pr[node] != 0)
    p1(endi, __pr[node], __v, __ne, __pr, __a, __start);
}

int main(){
  array<int, 2> ans = {INF, 0};

  fastio;
  cin >> n >> k;
  c.resize(n+1);
  ne.resize(n+1);
  _ne.resize(n+1);
  pr.resize(n+1);
  _pr.resize(n+1);
  a.resize(n+1);
  _a.resize(n+1);
  v.resize(n+1);
  _v.resize(n+1);

  for(int i = 1; i <= n; i++) 
    cin >> c[i];

  cin >> m >> l;
  x.resize(m+1);
  y.resize(l+1);

  for(int i = 1; i <= m; i++) cin >> x[i];
  for(int i = 1; i <= l; i++) cin >> y[i];

  endk = x[m];
  startm = x[1], startl = y[1];

  // 0

  for(int i = 1; i <= n; i++)
    v[c[i]].push_back(i);
  for(int i = n; i >= 1; i--)
    _v[c[i]].push_back(i);

  for(int i = 1; i <= m; i++)
    if(v[x[i]].empty()) goto zero;
  for(int i = 1; i <= l; i++)
    if(v[y[i]].empty()) goto zero;

  p0(v, ne, pr, x, m, 1);
  p0(_v, _ne, _pr, y, l, -1);

  // cout << "\n";
  // for(int i = 1; i <= n; i++) cout << ne[i] << " "; cout << "\n";
  // for(int i = 1; i <= n; i++) cout << pr[i] << " "; cout << "\n";
  // cout << "==============================\n";
  // for(int i = 1; i <= n; i++) cout << _ne[i] << " "; cout << "\n";
  // for(int i = 1; i <= n; i++) cout << _pr[i] << " "; cout << "\n";
  // cout << "\n";

  // 1

  vis.assign(n+1, false);
  for(int i : v[endk])
    p1(i, i, v, ne, pr, a, startm);
  vis.assign(n+1, false);
  for(int i : _v[endk])
    p1(i, i, _v, _ne, _pr, _a, startl);

  // for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
  // cout << "==============================\n";
  // for(int i = 1; i <= n; i++) cout << _a[i] << " "; cout << "\n";
  // cout << "\n";

  // 2

  prz = a[n];
  for(int i = n; i >= 1; i--){
    if(prz == 0 || (a[i] < prz && a[i] > 0)) prz = a[i];
    if(prz > 0)
      a[i] = prz;
  }
  prz = _a[1];
  for(int i = 1; i <= n; i++){
    if(prz == 0 || _a[i] > prz) prz = _a[i];
    if(prz > 0)
      _a[i] = prz;
  }
  
  // for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
  // cout << "==============================\n";
  // for(int i = 1; i <= n; i++) cout << _a[i] << " "; cout << "\n";
  // cout << "\n";

  // 3

  for(int i = 1; i <= k; i++){
    if(v[i].size() < 2 || a[pierw(i)] == 0 || _a[ost(i)] == 0)
      continue;
    int A = pierw(i), B = ost(i);
    if(i == startm) A++;
    if(i == startl) B--;
    // cout << "{" << A << ", " << B << "} : ";
    if(a[A] > 0 && _a[B] > 0){
      ans[0] = min(ans[0], a[A]);
      ans[1] = max(ans[1], _a[B]);
    }
  }
  // cout << "\n";
  // for(int i = 1; i <= k; i++) cout << pierw(i) << " "; cout << "\n";
  // cout << "==============================\n";
  // for(int i = 1; i <= k; i++) cout << ost(i) << " "; cout << "\n";
  // cout << "\n";
  // cout << "ANS = {" << ans[0] << ", " << ans[1] << "}\n";

  // 4

  if(ans[0] == INF || ans[1] == 0){
    zero:
    cout << "0";
    return 0;
  }

  vector<int> ansv;
  for(int i : v[endk])
    if(ans[0] <= i && i <= ans[1])
      ansv.push_back(i);

  cout << ansv.size() << "\n";
  for(int i : ansv)
    cout << i << " ";   
}