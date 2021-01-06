#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int n, k, sum = 0; cin >> n >> k; n *= 2; int n2 = n;
  char p; vector<string> V; string v = "";
  while(n2 > 0){
    cin >> p; v += p;
    if(cin.peek() == '\n'){
      V.push_back(v); n2--; v = "";
    }
  }
  for(int i = 0, suma1 = 0, suma2 = 0; i < n; i += 2, suma1 = 0, suma2 = 0){
if(V[i].size() >= k && V[i+1].size() >= k){
    for(int it = 0; it < V[i].size(); it++){
      if(V[i][it] == 'a' || V[i][it] == 'e' || V[i][it] == 'i' || V[i][it] == 'o' || V[i][it] == 'u' || V[i][it] == 'y'){
        suma1++;
      }
    }
    for(int it = 0; it < V[i+1].size(); it++){
      if(V[i][it] == 'a' || V[i][it] == 'e' || V[i][it] == 'i' || V[i][it] == 'o' || V[i][it] == 'u' || V[i][it] == 'y'){
        suma2++;
      }
    }
    if(suma1 == suma2) sum++;
  }}
  cout << sum;
}
