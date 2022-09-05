// * hard implementation
// * stack, dp (largest histogram on matrix 2d), 2d prefix sums, binary search
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n, k;
vector<vector<int>> v, pref;

bool isc(int x){
  return (k <= x && x <= 2*k);
}

bool iskless(int x){
  return (x < k);
}

void coutcoord(int y1, int x1, int y2, int x2){
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
}

void prepref(){
  pref.assign(n+1, vector<int>(n+1, 0));
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + v[i][j];
}

int sum2d(int i1, int j1, int i2, int j2){
  return (pref[i2][j2]
          - pref[i1-1][j2]
          - pref[i2][j1-1]
          + pref[i1-1][j1-1]);
}

int sumhist(int L, int R, int y, int h){
  int x1 = L, y1 = y-h+1, x2 = R, y2 = y;
  return sum2d(y1, x1, y2, x2);
}

array<int, 4> hist(vector<int> &h, vector<int> &hsum, int y){
  stack<int> s;
  vector<int> l(n+1, 0), r(n+1, n+1);
  
  for(int i = n; i >= 1; i--){
    while(!s.empty() && h[s.top()] > h[i]){
      l[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  s = stack<int>();
  for(int i = 1; i <= n; i++){
    while(!s.empty() &&h[s.top()] > h[i]){
      r[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  for(int pos = 1; pos <= n; pos++){
    if(h[pos] == 0) continue;
    int L = l[pos] + 1, R = r[pos] - 1;
    if(iskless(sumhist(L, R, y, h[pos]))) continue;

    while(!isc(sumhist(L, R, y, h[pos]))){
      int M = (L+R)/2;
      if(!iskless(sumhist(L, M, y, h[pos])))
        R = M;
      else
        L = M+1;
    }

    return {L, y-h[pos]+1, R, y};
  }
  return {0, 0, 0, 0};
}

signed main(){
  fastio;
  cin >> k >> n;
  v.assign(n+1, vector<int>(n+1, 0));
  
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      cin >> v[i][j];

  prepref();
  vector<int> h(n+1, 0), hsum(n+1, 0);

  for(int y = n; y >= 1; y--){
    for(int j = 1; j <= n; j++){
      if(h[j] != 0)
        hsum[j] -= v[y+1][j], h[j]--;
      while(y-h[j] >= 1 && hsum[j] + v[y-h[j]][j] <= 2*k)
        hsum[j] += v[y-h[j]][j], h[j]++;
    }

    auto ans = hist(h, hsum, y);
    if(ans[0]){
      cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
      return 0;
    }
  }
  cout << "NIE\n";
}
