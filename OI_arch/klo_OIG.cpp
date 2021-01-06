#include <iostream>
#include <vector>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);//booster
  int n, k, m, s;
  cin >> n >> k >> m;
  vector <vector<int>> V, IT;
  int M[n];
  for(int i = 0; i < n; i++){ //wyzerowanie masy i ilości klocków w pudełku
    vector <int> temp;
    for(int j = 0; j < m; j++){
      temp.push_back(0);
    }
    V.push_back(temp);
    IT.push_back(temp);
  }
  for(int i = 0; i < n; i++){ //wczytywanie poszczególnych mas
    cin >> M[i];
  }
  if(M[0] <= m){ //wypełnienie wyniku wartością z pierwszej kolumny
    s = M[0];
  }
  for(int i = 1; i <= m; i++){ //wypełniane 1 kolumny ręcznie
    if(i >= M[0]){
      V[0][i] = M[0];
      IT[0][i] = 1;
    }
  }
for(int w = 1; w < n; w++){
  for(int o = 1; o <= m; o++){ //wypełniane reszty kolumn
    if((o >= M[w]) && ((M[w]+V[w-1][o-M[w]])>V[w-1][o-1])){
      V[w][o] = (M[w]+V[w-1][o-M[w]]);
      IT[w][o] = (1 + (IT[w-1][o-M[w]]));
    }
    if(o < M[w] || ((M[w]+V[w-1][o-M[w]]) <= V[w-1][o-1])){
      V[w][o] = V[w-1][o];
      IT[w][o] = IT[w-1][o];
    }
    if(IT[w][o] <= k){
      s = max(s, V[w][o]);
    }
  }
}
cout << s; //wynik
}
