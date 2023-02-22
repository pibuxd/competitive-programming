#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n;
vector<array<int, 2>> V;

array<int, 2> mid(const array<int, 4> &x){
  return {x[0]+x[2], x[1]+x[3]};
}

int len(const array<int, 4> &x){
  return abs(x[0]-x[2])*abs(x[0]-x[2]) + abs(x[1]-x[3])*abs(x[1]-x[3]);
}

signed main(){
  fastio;
  cin >> n;
  V.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> V[i][0] >> V[i][1];
  // mid(x) to wspolrzedzne srodka odcinka x
  // odcinki a, b to przekatne prostokata
  // |a| = |b| && mid(a) == mid(b)
  map<pair<int, array<int, 2>>, int> M;

  for(int i = 1; i <= n; i++){
    for(int j = i+1; j <= n; j++){
      array<int, 4> odc = {V[i][0], V[i][1], V[j][0], V[j][1]};
      M[make_pair(len(odc), mid(odc))]++;
    }
  }
  int sum = 0;

  for(auto it : M){
    int f = it.second;
    sum += (f*(f-1))/2;
  }

  cout << sum << "\n";
}
