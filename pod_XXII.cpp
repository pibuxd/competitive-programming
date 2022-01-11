#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, k;
vector<int> r;
vector<array<int, 2>> p;

int main(){
  fastio;
  cin >> n >> k;
  r.resize(n+1);
  p.resize(k+1, {n+1, 0});

  for(int i = 1; i <= n; i++){
    cin >> r[i];
    p[r[i]] = {min(p[r[i]][0], i), i};
  }

  p[0] = {0, 0};
  sort(all(p));

  for(int i = 1; i <= k; i++)
    cout << p[i][0] << ", " << p[i][1] << "\n";

  
}