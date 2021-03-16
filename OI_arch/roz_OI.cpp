#include "bits/stdc++.h"
using namespace std;

int main(){
  int n; cin >> n;
  char C[n], IT[n];
  cin >> C[0];
  vector<int> ZLICZ;
  int sum[26];
  fill(sum, sum+26, 0);
  int sorted[26];
  for(int i = 1, licz = 1, it = 0; i < n; i++){ //zliczanie dlugosci poszeczegolnych podstringow
    cin >> C[i];

    if(C[i] == C[i-1]){
      licz++;
    }
    else if(C[i] != C[i-1]){
      sum[C[i]-97] += licz;
      sorted[C[i]-97] += licz;
      IT[it] = C[i];
      it++;
      ZLICZ.push_back(licz);
      licz = 1;
    }
  }

  sort(sorted, sorted+26);
  int x = 0;
  while(sorted[x] == 0){
    x++;
  }
  int min = sorted[25] - sorted[x];

  while(true){
    if
  }

}
