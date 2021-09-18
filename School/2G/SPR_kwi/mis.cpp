#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<int> a;

int main(){
  fastio;
  auto n = 0;
  cin >> n;

  vector<int> a(n);

  for(auto &i : a){
    cin >> i;
  }

  auto minimum = make_pair(0, 10000000);
  vector<int> w(n);

  for(int i = n- 1; i >= 0; i--){
    w[i] = min(w[i+1] + a[i], a[i]);
    if(minimum.second >= w[i]){
      minimum = {i, w[i]};
    }
  }

  cout << minimum.first+1 << " " << minimum.second;
}