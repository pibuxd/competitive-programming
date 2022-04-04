// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct trio{
  int first;
  int second;
  int third;
};

bool sortByDanger(const trio &a, const trio &b){
  if(a.first < b.first) return true;

  else if(b.first < a.first) return false;

  else if(a.first == b.first){
    if(a.third < b.third) return true;
    else return false;
  }
}

int main(){ fastio;
  int n; cin >> n;

  vector<trio> V;

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    int b; cin >> b;

    V.push_back(trio());
    V[i].first = b;
    V[i].second = a;
    V[i].third = i;
  }
  sort(V.begin(), V.end(), sortByDanger);

  for(int i = 0; i < n; i++){
    cout << V[i].second << '\n';
  }
}
