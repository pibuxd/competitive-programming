#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int n, it = 0, x = 0; cin >> n; long long sum = 0;
  int V[n + 1], T[n + 1], I[n + 1];
  for(int i = 0; i < n; i++){
    cin >> V[i]; T[i] = V[i]; I[V[i]] = i;
  } sort(T, T + n);
  for(int i = 0; i < n; i++){
    while(I[T[it]] < i){it++;}
    if(V[i] == T[it]){
      sum += T[it] * ((i + 1) - x); x = i + 1; cout << sum << endl;
    }
  }
  cout << sum;
}
