// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include<bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> V(n);

  for(int i = 0; i < n; i++)
    cin >> V[i];

  long long sum = 0;
  for(int i = 0; i < n-1; i++){
    if(V[i] > V[i+1]){
      sum += (V[i] - V[i+1]);
      V[i+1] = V[i];
    }
  }
  if(V[n-1] < V[n-2])
    sum += (V[n-2] - V[n-1]);
  cout << sum;
}
