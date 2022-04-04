// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n, INF = 1e17;
vector<int> a, b;

int calc(const vector<int> &p){
  vector<bool> vis(n+1, false);
  int sum = 0;

  for(int x : p){
    array<int, 2> mnl = {INF, 0};

    for(int i = 1; i <= n; i++){
      if(!vis[i]){
        int dif = abs(a[x] - b[x]);
        if(dif < mnl[0]){
          mnl = {dif, i};
        }
      }
    }

    sum += mnl[0];
    vis[mnl[1]] = true;
  }

  return sum;
}

signed main(){
  fastio;
  cin >> n;

  a.resize(n+1);
  b.resize(n+1);

  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];

  vector<int> p, ans;

  for(int i = 1; i <= n; i++) p.push_back(i);

  int mn = INF;
  do {
    int c = calc(p);
    if(c < mn)
      ans = p, mn = c;

  } while(next_permutation(all(p)));


  cout << mn << "\n";
  for(int i : ans) cout << i << " ";
}