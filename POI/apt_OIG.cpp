// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef unsigned long long ull;

ull n;
ull sum = 0;
vector<ull> V;

int main(){
  fastio;

  cin >> n;
  V.resize(n+1);

  for(ull i = 1; i <= n; i++){
    cin >> V[i];
  }

  ull minimum = V[n];
  stack<pair<ull, ull>> S;
  S.push({minimum, n});

  for(ull i = n; i >= 1; i--){
    if(V[i] < minimum){
      S.push({V[i], i});
      minimum = V[i];
    }
  }

  ull it = 0;

  while(!S.empty()){
    auto x = S.top();
    S.pop();

    sum += x.first * (x.second - it);
    it = x.second;
  }
  
  cout << sum;
}
