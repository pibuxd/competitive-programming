#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define MX (int)(2e5)

vector<pair<int, int>> factors(int n){
  vector<pair<int, int>> ret;

  for(int i = 2; i * i <= n; i++){
    int cnt = 0;
    while(n % i == 0){
      cnt++;
      n /= i;
    }
    if(cnt)
      ret.push_back({i, cnt});   
  }
  
  if(n > 1)
    ret.push_back({n, 1});

  return ret;
}

int quick_power(int a, int b){
  int ans = 1;
  while(b > 0){
    if(b % 2 == 1)
      ans *= a;
    a *= a;
    b /= 2;
  }

  return ans;
}

signed main(){
  fastio;
  int n;
  cin >> n;

  vector<pair<int, int>> M(MX+1, {MX, MX});
  vector<int> licz(MX, 0);

  for(int i = 1; i <= n; i++){
    int a; cin >> a;
    auto fac = factors(a);

    for(auto f : fac){
      int num = f.first, cnt = f.second;
      licz[num]++;
      auto m = M[num];

      if(cnt <= m.first)
        M[num] = {cnt, m.first};
      else if(cnt < m.second)
        M[num] = {m.first, cnt};
    }
  }

  int ans = 1;
  for(int i = 1; i <= MX; i++){
    int p = M[i].second;

    if(n-licz[i] == 1)
      p = M[i].first;
    else if(n-licz[i] >= 2)
      p = 0;

    ans *= quick_power(i, p);
  }

  cout << ans;
}
