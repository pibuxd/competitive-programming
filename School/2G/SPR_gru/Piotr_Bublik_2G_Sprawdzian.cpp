// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

//zadanie 1
// A-P, B-F, C-P, D-P

//zadanie 2
void zapisBINARNY(int x){
  if(!x)
    return;
  zapisBINARNY(x >> 1);
  cout<< (x&1) <<' ';
}

//zadanie 3
// REKURENCYJNA
int funcREK(int x){
  if(x == 0)
    return 0;

  if(x % 2 == 0)
    return funcREK(x / 2);
  
  return funcREK(x - 1) + 1;
}
// NIEREKURENCYJNA
int funcNIEREK(int x){
  int wynik = 0;
  while(x){
    if(x&1) {
      wynik++;
      x--;
    }
    else x /= 2;
  }
  return wynik;
}

// Wypisywanie wynikow
int main(){
  cout << "Zadanie 1:\nA-P, B-F, C-P, D-P\n\nZadanie 2:\n";
  zapisBINARNY(10);
  cout << "\n\nZadanie 3:\n";

  cout << "\tFunkcja Rekurencyjna:\n";
  for(int i = 0; i <= 40; i++)
    cout << funcREK(i) << ' ';
  
  cout << "\n\n\tFunkcja Nierekurencyjna:\n";
  for(int i = 0; i <= 40; i++)
    cout << funcNIEREK(i) << ' ';
}
