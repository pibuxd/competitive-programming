// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <iostream>
#include <algorithm>
using namespace std;

void booster(){
  ios_base::sync_with_stdio(0);
}

int main(){ booster();
  int testy;
  cin >> testy;

  while(testy--){
    int ilosc_mosiadzow;
    cin >> ilosc_mosiadzow;

    int wynik[ilosc_mosiadzow+1]; //wyniki dla podproblemu
    int mosiadze[ilosc_mosiadzow+1]; //mosiądze

    for(int iterator = 1; iterator <= ilosc_mosiadzow; iterator++){ //wczytywanie
      cin >> mosiadze[iterator];
    }

    wynik[0] = 0;
    wynik[1] = mosiadze[1];
    wynik[2] = mosiadze[1] + mosiadze[2];

    for(int iterator = 3; iterator <= ilosc_mosiadzow; iterator++){
      wynik[iterator] = max(max(wynik[iterator-1], wynik[iterator-2] + mosiadze[iterator]), wynik[iterator-3] + mosiadze[iterator] + mosiadze[iterator-1]); //szukanie najwyższego wyniku
    }

    cout << wynik[ilosc_mosiadzow] << '\n';
  }
}
