#include <bits/stdc++.h>
using namespace std;

void insert(int gdzie, int pocz, int kon, int ile, int n){//wstawia ile na wszystkie pozycje

      if(x == pocz && kon == x){
         dr[gdzie] += ile;
         return;
      }
      int sr = (pocz + kon) / 2;

      if(x <= sr)
         insert(2 * gdzie, pocz, sr, x, ile);      //jesli trzeba iść w lewo
      else
         insert(2 * gdzie + 1, sr + 1, kon, x, ile);//w przeciwnym wypadku

      dr[gdzie] = dr[2 * gdzie] + dr[2 * gdzie + 1];//aktualizujemy drzewo
}

int query(int gdzie, int pocz, int kon, int x, int y){ //suma od x do y
   if(x <= pocz && y >= kon) //jesli mamy przedzial bazowy, to sumujemy
      return dr[gdzie];

   int sr = (pocz + kon) / 2, wynik = 0;
   //schodzimy w lewo i prawo dodajac do wyniku
   if(x <= sr)
      wynik += query(2 * gdzie, pocz, sr, x, y);
   if(y > sr)
      wynik += query(2 * gdzie, sr + 1, kon, x, y);

   return wynik;
}

int main(){ //ios_base::sync_with_stdio(0);
   int n, m;
   cin >> n >> m;
   int dr[(n * 2) - 1] //drzewo

   for(int i = 0; i < m; i++){
      int p;
      cin >> p;

      if(p == (n + 1))

   }
}
