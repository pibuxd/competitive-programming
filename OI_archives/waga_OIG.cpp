#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int cg, lw, pr; //liczba: cegiełek, wież na lewej i prawej szalce
  cin >> cg >> lw >> pr;
  int sl = 0, sp = 0; //suma cegiełek na lewej i prawej szalce
  int L[cg*lw], P[cg+pr]; //cegiełki w lewej i prawej szalce
  for(int i = 0; i < (lw*cg); i++){ //wczytywanie cegiełek na lw szalce i sumowanie ich
    cin >> L[i];
    sl += L[i];
  }
  for(int i = 0; i < (pr*cg); i++){ //wczytywanie cegiełek na pr szalce i sumowanie ich
    cin >> P[i];
    sp += P[i];
  }
}
