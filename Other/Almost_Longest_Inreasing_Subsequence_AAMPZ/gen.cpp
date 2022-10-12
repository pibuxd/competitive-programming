#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int ranint(int a, int b){
  return a + rand()%(b-a+1);
}

vector<int> ranperm(int n){
  vector<int> v;
  for(int i = 1; i <= n; i++) v.push_back(i);

  for(int i = 1; i <= 1000000000; i++)
    swap(v[ranint(0, n-1)], v[ranint(0, n-1)]);
  return v;
}

signed main(){
  fastio;
  int seed; cin >> seed;
  srand(seed);

  int n = 1e5;
  vector<int> v = ranperm(n);

  cout << n << "\n";
  for(int x : v) cout << x << "\n";
}
