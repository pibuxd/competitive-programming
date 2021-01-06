#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p, licznik = 0, wynik;
    cin >> n;
    bool tab[n];
    for (int a = 0; a < n; a++) {
        cin >> p;
        if (p == 0)
            tab[a] = true;
        else{
            tab[a] = false;
            licznik++;
        }
    }
    wynik = licznik;
    for(int a = 0; a < n; a++){
        if (tab[a])
            licznik++;
        else licznik--;
        wynik = min(wynik, licznik);
    }
    cout << wynik;
}
