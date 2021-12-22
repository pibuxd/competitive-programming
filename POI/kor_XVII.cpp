#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int uint64_t

#define M ((uint64_t)(1ull<<61) - 1)
#define P ((uint64_t)23)

int n;
vector<int> a, p1, h1;

int check(int k){
  unordered_set<int> S1;

  for(int i = 1; k*i <= n; i++){
    int hs1 = (h1[k*i] - h1[k*(i-1)] + M) % M;
    if(!S1.count(hs1))
      S1.insert(hs1);
  }

  return S1.size();
}

signed main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  p1.resize(n+1);
  h1.resize(n+1);

  p1[0] = 1;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    p1[i] = (i == 1) ? 1 : ((p1[i-1] * P) % M);
  }

  for(int i = 1; i <= n; i++)
    h1[i] = (h1[i-1] + (a[i] * p1[a[i]]) % M ) % M;

  int mx = 0;
  vector<int> ans;
  for(int i = 1; i <= n; i++){
    int c = check(i);

    if(c == mx)
      ans.push_back(i);
    else if(c > mx){
      ans.clear();
      ans.push_back(i);
      mx = c;
    }
  }

  cout << mx << " " << ans.size() << "\n";
  for(auto res : ans)
    cout << res << " ";
}