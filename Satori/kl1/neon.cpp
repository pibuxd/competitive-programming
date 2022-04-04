// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

void booster(){
  ios_base::sync_with_stdio(0);
}

int main(){
  booster();
  int t; cin >> t;

  while(t--){
    string A, B; cin >> A >> B;
    int as = A.size(), bs = B.size();

    int DP[as+1][bs+1];
    int ARR[as+1][bs+1];

    for(int i = 0; i <= as; i++){
      for(int j = 0; j <= bs; j++){

        if(i == 0 || j == 0) //zerowanie 0 kolumny i 0 wiersza
          DP[i][j] = 0;

        else{
          if(A[i-1] == B[j-1]){
            DP[i][j] = DP[i-1][j-1] + 1;
            ARR[i][j] = 1; //na ukos
          }

          else{
            if(DP[i-1][j] >= DP[i][j-1]){
              DP[i][j] = DP[i-1][j];
              ARR[i][j] = 2; //do gory
            }
            else{
              DP[i][j] = DP[i][j-1];
              ARR[i][j] = 3; //w lewo

            }
          }
        }
      }
    }
    cout << DP[as][bs] << '\n';

    stack<char> S;
    int i = as, j = bs, x = DP[as][bs];

    while(x > 0){
      char p = B[j-1];

      if(ARR[i][j] == 1){

        if(DP[i-1][j-1] == x - 1){
          S.push(p);
          x--;
        }
        i--;
        j--;
      }

      if(ARR[i][j] == 2){

        if(DP[i-1][j] == x - 1){
          S.push(p);
          x--;
        }
        i--;
      }

      if(ARR[i][j] == 3){

        if(DP[i][j-1] == x - 1){
          S.push(p);
          x--;
        }
        j--;
      }
    }

    while(!S.empty()){
      cout << S.top();
      S.pop();
    }
    cout << '\n';
  }
}
