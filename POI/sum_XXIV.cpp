// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sumcyfr(int z){ //liczenie sumy cyfr w liczbie
  int sum = 0;
  while(z != 0){
    sum += z % 10;
    z /= 10;
  }
  return sum;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); //booster
  int scfr, mod, n; //suma cyfr, podzielnik, liczba przykładów
  cin >> scfr >> mod >> n;
  ll k; //k-ta najmniejsza liczba spełniająca warunki ↑
  ll num = mod, ktr = 0; //liczba spełniająca warunki ↑, która z kolei liczba
  for(int j = 0, sc; j < n; j++, ktr = 0, num = mod){
    cin >> k; //wczytywanie
    while(ktr < k){
      sc = sumcyfr(num); //suma cyfr, aby nie tracić czasu na ciągłe liczenie od nowa
      if(sc == scfr){
        ktr++;
      }
      else{
        while(sc != scfr){
          num += mod
          if((num % 10 < (num - mod) % 10) && (num )){
            sc += (num % 10) -
          }
        }
      }
      num += mod;
    }
    cout << num - mod << '\n';
  }
}
