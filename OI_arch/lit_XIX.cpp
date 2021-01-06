#include <bits/stdc++.h>
using namespace std;

int n = 0;

struct ToChange{
  bool kierunek;
  int start;
  int odl;
};

void initValues(ToChange &S, int a, vector<int> IT){
  S.odl = 10000001;
  for(int i = 0; i < IT.size(); i++){
    int x = abs(IT[i] - i);
    if(S.odl > x){
      S.odl = x;
      if(IT[i] - i > 0) S.kierunek = 0;
      else S.kierunek = 1;
      S.start = IT[i];
    }
  }
}

void changePos(ToChange S, int koniec, vector<vector<int>> &IT, char A[]){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < IT[A[i]-64].size(); j++){
      if(S.kierunek){
        if(IT[A[i]-64][j] >= S.start && IT[A[i]-64][j] < koniec)
          IT[A[i]-64][j]--;
      } else{
        if(IT[A[i]-64][j] <= S.start && IT[A[i]-64][j] > koniec)
          IT[A[i]-64][j]++;
      }
    }
  }
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  long long ans = 0;

  char A[n];
  vector<vector<int>> IT(27);
  for(int i = 0; i < n; i++){
    cin >> A[i];
    IT[A[i]-64].push_back(i);
  }

  char B;
  for(int i = 0; i < n; i++){
    cin >> B;
    if(B != A[i]){
      ToChange S;
      initValues(S, i, IT[B-64]);
      changePos(S, i, IT, A);
      ans += S.odl;
    }
  }

  cout << ans;
}
