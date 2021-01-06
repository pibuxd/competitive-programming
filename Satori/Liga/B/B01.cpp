#include <bits/stdc++.h>
using namespace std;

vector<int> ile(2000001);

long long addAns(int n){
  long long wynik = 0;

  for(int i = 2; i <= sqrt(n); i++){
    if(n%i == 0){
      wynik += ile[i] * ile[n];

      if(n/i != i)
        wynik += ile[n/i] * ile[n];
    }
  }
  if(n != 1)
    wynik += ile[1] * ile[n];

  return wynik;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> liczby;

  while(n--){
    int temp; cin >> temp;
    ile[temp]++;

    if(ile[temp] == 1)
      liczby.push_back(temp);
  }
  long long ans = 0;

  for(int i = 0; i < liczby.size(); i++){
    ans += addAns(liczby[i]);
    ans += ile[liczby[i]] * (ile[liczby[i]] - 1);
  }

  cout << ans;
}
