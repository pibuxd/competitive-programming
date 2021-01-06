#include "bits/stdc++.h"
using namespace std;

int sumaOf(string str1, string str2, int ktora, int size){
  if(ktora == (size+1)){
    for(int i = 0; i < size; i++){
      int sum = (int)str1[i] - 96 + (int)str2[i];

      if(sum > 9)
        return 1;
      else if(sum < 9)
        return 0;
    }
    return 0;
  }

  int sum = (int)str1[size - ktora] - 96 + (int)str2[size - ktora];

  for(int i = (size - ktora + 1); i < size; i++){
    int sumarum = (int)str1[i] - 96 + (int)str2[i];

    if(sumarum > 9 && sum > 8)
      return sum - 9;
    else if(sumarum > 9 && sum < 9)
      return sum + 1;

    else if(sumarum < 9 && sum <= 9)
      return sum;
    else if(sumarum < 9 && sum > 9)
      return sum - 10;
  }
  if(sum > 9)
    return sum - 10;
  else
    return sum;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int size, tests; cin >> size >> tests;
  string wewn, zewn; cin >> wewn >> zewn;
  int sizex = wewn.size();

  while(tests--){
    char operacja; cin >> operacja;
    int ktora; cin >> ktora;

    if(operacja != 'S'){
      char nowa; cin >> nowa;

      if(operacja == 'W')
        wewn[sizex - ktora] = nowa;
      else
        zewn[sizex - ktora] = nowa;
    }
    else{
      cout << sumaOf(wewn, zewn, ktora, size-1) << '\n';
    }
  }
}
