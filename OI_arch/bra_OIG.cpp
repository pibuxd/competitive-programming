#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); //boosters
  int n, dis = 0, s = 1;
  cin >> n;
  int V[n], po[10001], ko[10001], Z[10001] = {0}, DIS[10001];
  for(int i = 0; i < n; i++){ //wczyt, szukanie poczatku i konca dla danych rodzin
    cin >> V[i];
    if(Z[V[i] == 0]){
      Z[V[i]] = 1;
      DIS[dis] = V[i];
      dis++;
      po[V[i]] = i;
    }
    ko[V[i]] = i;
  }
  for(int i = 0; i < dis; i++){
    for(int j = po[DIS[i]]; j < ko[DIS[i]]; j++){

    }
  }
  cout << s; //wynik końcowy
}
