// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;

int endpoint(int p, int k, int x){
  int len = k-p+1;
  int ile = len/x;
  int en = p + ile*x;
  return en;
}

int main(){
  fastio;
  cin >> n;

  vector<array<int, 3>> in(n+1);
  bool pod = true;

  for(int i = 1; i <= n; i++){
    int p, k, x; cin >> p >> k >> x;
    in[i] = {p, k, x};

    if(x > 1)
      pod = false;
  }

  if(!pod){
    map<int, int> M;

    for(int t = 1; t <= n; t++){
      int p = in[t][0], k = in[t][1], x = in[t][2];

      for(int i = 0; p + i * x <= k; i++){
        M[p + i * x]++;
      }
    }
    for(auto i : M){
      if(i.second % 2 != 0){
        cout << i.first << " " << i.second;
        return 0;
      }
    }

    cout << "NIE";
    return 0;

  } else{
    map<int, int> M;

    for(int t = 1; t <= n; t++){
      int p = in[t][0], k = in[t][1], x = in[t][2];

      M[p]++;
      M[endpoint(p, k, x)+1]--;
    }

    int curr = 0;
    for(auto i : M){
      curr += i.second;
      if(curr % 2 != 0){
        cout << i.first << " " << curr;
        return 0;
      }
    }

    cout << "NIE";
    return 0;
  }
}