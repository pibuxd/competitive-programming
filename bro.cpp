#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<array<int, 2>> v;

int main(){
  fastio;
  cin >> n;
  int kr = 0, cr = 0;
  v.resize(n+1);

  for(int i = 1; i <= n; i++){
    cin >> v[i][0] >> v[i][1];
    cr += kr * v[i-1][1];
    kr += v[i][0];
  }

  int mn = cr, cl = 0, kl = 0;
  for(int i = 1; i <= n; i++){
    cl += kl * v[i-1][1];
    cr -= kr * v[i-1][1];
    kl += v[i][0];
    kr -= v[i][0];
    mn = min(mn, cl + cr);
    cout << mn << " ";
  }

  cout << mn;
}