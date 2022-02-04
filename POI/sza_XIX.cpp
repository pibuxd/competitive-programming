#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MXK 1e5
#define INF 1e9

int n;
vector<array<int, 3>> skl;
vector<int> najtw;

bool ok(int k, int b){
  return najtw[k] >= b;
}

void newskl(array<int, 3> x){
  int b = x[1], c = x[2];
  for(int i = MXK; i >= c; i--)
    najtw[i] = max(najtw[i], min(najtw[i-c], b));
}

int main(){
  fastio;
  cin >> n;
  skl.resize(n+1);
  najtw.resize(MXK+1, 0);

  for(int i = 1; i <= n; i++){
    int c, a, b; cin >> c >> a >> b;
    skl[i] = {a, b, c};
  } sort(skl.begin(), skl.end());

  int p; cin >> p;
  vector<array<int, 4>> pz(p+1);

  for(int i = 1; i <= p; i++){
    int m, k, s; cin >> m >> k >> s;
    pz[i] = {m, k, s, i};
  } sort(pz.begin(), pz.end());

  vector<int> ans(p+1);

  najtw[0] = INF;
  for(int i = 1, si = 1; i <= p; i++){
    int m = pz[i][0], k = pz[i][1], s = pz[i][2];

    while(si <= n && skl[si][0] <= m){
      newskl(skl[si]);
      si++;
    }

    ans[pz[i][3]] = (ok(k, m+s+1) ? 1 : 0);
  }

  for(int i = 1; i <= p; i++)
    cout << (ans[i] == 1 ? "TAK" : "NIE") << "\n";
}