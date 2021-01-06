#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
ios_base::sync_with_stdio(0);
int n, z, I[1000001], it = 0; ll m; cin >> n >> m;
ll H[1000001], sum = 0, g = 0;
  for(int i = 0; i < n; i++){ cin >> H[i];
    if(H[i] >= m){ g++; I[it] = i; it++; }
  }
  for(int i = 0; i < g; i++){
    if((i+1) < g) sum += (I[i]+1) * (I[i+1] - I[i]);
    if(i == (g-1)) sum += (I[i]+1) * (n-I[i]);
  } cout << sum;
}
