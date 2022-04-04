// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n;
vector<array<int, 2>> p;

void _print(auto x){
  cout << x[1] << " " << x[0] << " ";
}

void print(auto a, auto b, auto c){
  // cout << "{ ";
  _print(a); _print(b); _print(c);
  // cout << "}\n";
}

bool t(array<int, 3> tri){
  return tri[2] < tri[0] + tri[1] && tri[1] < tri[0] + tri[2] && tri[0] < tri[1] + tri[2];
}

bool ok(auto a, auto b, auto c){
  return (a[1] != b[1] && b[1] != c[1] && a[1] != c[1]
          && t({a[0], b[0], c[0]}));
}

int main(){
  fastio;
  cin >> n;

  for(int c = 1; c <= n; c++){
    int z; cin >> z;

    for(int j = 1; j <= z; j++){
      int x; cin >> x;
      p.push_back({x, c});
    }
  }

  sort(all(p));

  auto a = p[0], b = p[1];
  
  for(int i = 2; i < p.size(); i++){
    auto c = p[i];
    // print(a, b, c);

    if(ok(a, b, c)){
      print(a, b, c);
      return 0;
    }
    if(a[0] > b[0])
      swap(a, b);

    if(b[1] == c[1])
      a = b, b = c;
    else if(a[1] == c[1])
      a = c;
    else if(a[1] == b[1])
      a = c;
  }

  cout << "NIE";
}