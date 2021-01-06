#include <iostream>
#include <bitset>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int t;
  cin >> t;

  while(t--){
    int n, k;
    cin >> n >> k;
    bitset<1000001> P; //pułapki na danym polu
    int W[n+1]; //liczba sposobów na dane pole (wynik)
    W[1] = 1;

    for(int i = 1; i <= n; i++){ //wczytywanie
      char p;
      cin >> p;
      if(p == '0')
        P[i] = false;
      else
        P[i] = true;
    }

    for(int i = 2; i <= n; i++){
      if(!P[i])
        W[i] = 0;

      else{
        if(i == 2)
          W[2] = 1;

        else if(i == 3)
          W[3] = (W[2] + 1) % k;

        else if(i == 4)
          W[4] = (W[3] + W[2] + 1) % k;

        else if(i == 5)
          W[5] = (W[4] + W[3] + W[2] + 1) % k;

        else if(i == 6)
          W[6] = (W[5] + W[4] + W[3] + W[2] + 1) % k;

        else
          W[i] = (W[i-1] + W[i-2] + W[i-3] + W[i-4] + W[i-5] + W[i-6]) % k;
      }
    }
    cout << W[n] % k << '\n'; //wypisanie wyniku
  }
}
