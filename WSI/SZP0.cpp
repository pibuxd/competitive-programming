#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, q, N;
vector<vector<int>> szp, zdjfront, zdjback;
unordered_map<int, int> id;
vector<int> ans, lic, bit;

void add(int idx, int val){
  for(; idx <= N; idx += idx & -idx)
    bit[idx] += val;
}

void add(int l, int r, int val){
  add(id[l], val); add(id[r]+1, -val);
}

int qry(int idx){
  idx = id[idx];
  int res = 0;
  for(; idx >= 1; idx -= idx & -idx)
    res += bit[idx];
  return res;
}

int main(){
  fastio;
  cin >> n >> q;
  ans.resize(q+1, 0);

  for(int i = 1; i <= n; i++){
    int a, b, c, d; cin >> a >> b >> c >> d;
    a++, b++, c++, d++;
    lic.push_back(a); lic.push_back(b); lic.push_back(c); lic.push_back(d);
    zdjfront.push_back({a, b, d});
    zdjback.push_back({c, d, b});
  }
  for(int i = 1; i <= q; i++){
    int a, b; cin >> a >> b;
    a++, b++;
    lic.push_back(a); lic.push_back(b);
    szp.push_back({a, b, i});
  }
  
  sort(all(lic));
  N = 0;
  int last = -1;
  for(int x : lic)
    if(x != last)
      id[x] = ++N, last = x;
  
  bit.assign(N+2, 0);
  sort(all(zdjfront));
  sort(all(zdjback));
  sort(all(szp));

  auto szpit = szp.begin();
  auto zdjfrontit = zdjfront.begin();
  auto zdjbackit = zdjback.begin();

  while(szpit != szp.end()){
    while(zdjfrontit != zdjfront.end() && (*zdjfrontit)[0] <= (*szpit)[0]){
      add((*zdjfrontit)[1], (*zdjfrontit)[2], 1);
      zdjfrontit++;
    }
    while(zdjbackit != zdjback.end() && (*zdjbackit)[0] < (*szpit)[0]){
      add((*zdjbackit)[2], (*zdjbackit)[1], -1);
      zdjbackit++;
    }
    ans[(*szpit)[2]] = qry((*szpit)[1]);
    szpit++;
  }

  for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
