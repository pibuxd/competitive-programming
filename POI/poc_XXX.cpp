#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, m, k;
vector<int> a, b;
vector<vector<int>> v;

int main(){
  fastio;
  //cout << "\n";
  cin >> n >> m >> k;

  a.assign(n+1, 0);
  b.assign(m+1, 0);
  v.assign(k+1, {0});

  for(int i = 1; i <= n; i++) cin >> a[i];
  
  for(int i = 1; i <= m; i++){
    cin >> b[i];
    v[b[i]].push_back(i);
  }
  
  vector<int> l(n+1, 0);
  vector<int> pom(k+1, 0), pomit(k+1, 0);

  for(int i = 1; i <= n; i++){
    l[i] = pom[a[i]];
    if(pomit[a[i]] == v[a[i]].size()-1) continue;

    if(pom[b[v[a[i]][pomit[a[i]]+1] - 1]] + 1 == v[a[i]][pomit[a[i]]+1]){
      pom[a[i]] = v[a[i]][pomit[a[i]]+1];
      pomit[a[i]]++;
    }
    l[i] = pom[a[i]];
  }

  vector<int> r(n+1, 0);
  pom.assign(k+1, 0);
  pomit.assign(k+1, 0);
  for(int i = 1; i <= k; i++){
    v[i].push_back(0);
    reverse(all(v[i]));
    for(int &x : v[i]) x = m+1-x;
  }
  b.push_back(0);
  reverse(all(b));
  for(int i = n; i >= 1; i--){
    r[i] = pom[a[i]];
    if(pomit[a[i]] == v[a[i]].size()-2) continue;

    if(pom[b[v[a[i]][pomit[a[i]]+1] - 1]] + 1 == v[a[i]][pomit[a[i]]+1]){
      pom[a[i]] = v[a[i]][pomit[a[i]]+1];
      pomit[a[i]]++;
    }
    r[i] = pom[a[i]];
  }

  //for(int i = 1; i <= n; i++) cout << l[i] << " "; cout << "\n";
  //for(int i = 1; i <= n; i++) cout << r[i] << " "; cout << "\n";
  
  vector<int> idr(m+1, 0);
  
  for(int i = 1; i <= n; i++)
    idr[r[i]] = i;

  int currid = 0;

  for(int i = 1; i <= n; i++){
    currid = max(currid, idr[m-l[i]]);

    if((l[i] > 0 && idr[m-l[i]] > i) || l[i] == m) cout << 1 << " ";
    else cout << 0 << " ";
  }
}
