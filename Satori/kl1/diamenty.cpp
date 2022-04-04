// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

//#define diax diament

void booster(){
  ios_base::sync_with_stdio(0);
}

int main(){
  booster();
  int t; //ilosc testow
  cin >> t;

  while(t--){
    int n, m;
    cin >> n >> m;
    bool D[m+1][n+1]; //czy na danym polu jest diament

    for(int i = 1; i <= m; i++){
      for(int j = 1; j <= n; j++){
        cin >> D[i][j];
      }
    }
    int W[m+1][n+1]; //wynik ile diaxow po dordze gdy konczymy na danym polu

    for(int i = 1; i <= n; i++){
      W[0][i] = 0;
    }
    for(int i = 0; i <= m; i++){
      W[i][0] = 0;
    }

    bool GD[m+1][n+1]; //skad jest dany wynik

    for(int i = 1; i <= m; i++){
      for(int j = 1; j <= n; j++){

        if(W[i-1][j] >= W[i][j-1] && i > 1){
          W[i][j] = W[i-1][j];
          GD[i][j] = true; //v
        }

        else if(W[i-1][j] >= W[i][j-1] && i == 1){
          W[i][j] = W[i-1][j];
          GD[i][j] = false; //>
        }

        else if(W[i-1][j] < W[i][j-1] && j > 1){
          W[i][j] = W[i][j-1];
          GD[i][j] = false; //>
        }

        else if(W[i-1][j] < W[i][j-1] && j == 1){
          W[i][j] = W[i][j-1];
          GD[i][j] = true; //v
        }

        if(D[i][j]){ //jesli na danym polu jest diax
          W[i][j]++;
        }
      }
    }
    cout << W[m][n] << ' ';

    stack<char> S; //przechowywanie sciezki
    int i = m, j = n; //zmienne pomocnicze

    while(i > 0 && j > 0){ //szukanie sciezki
      if(GD[i][j]){
        S.push('v');
        i--;
      }

      else{
        S.push('>');
        j--;
      }
    }

    S.pop();
    while(!S.empty()){ //wypisywanie sciezki
      cout << S.top();
      S.pop();
    }
    cout << '\n';
  }
  //koniec programu GG EZ :)
}
