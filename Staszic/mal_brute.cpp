// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, q;
vector<int> t;

void update(int a, int b){
  while(a <= b){
    t[a] = !t[a];
    a++;
  }
}

int query(int a, int b){
  int res = 0;
  while(a <= b){
    res += t[a];
    a++;
  }

  return res;
}

int main(){
  fastio;
  cin >> n >> q;
  t.resize(n+1, 1);

  while(q--){
    char op;
    int a, b;
    cin >> op >> a >> b;

    if(op == '?')
      cout << query(a, b) << "\n";
    else
      update(a, b);
  }
}

/*
13 40
* 7 13
* 5 6
* 1 2
* 9 12
* 8 13
? 5 7
* 1 11
? 3 11
* 7 11
? 5 12
? 4 9
? 6 7
* 5 13
? 2 10
? 6 6
? 2 7
* 2 11
* 8 13
* 1 8
? 9 12
* 3 12
* 5 6
* 6 9
* 1 2
* 3 11
* 12 13
? 8 11
* 10 10
* 3 10
* 9 10
? 10 13
? 3 8
? 1 4
? 5 8
* 2 8
? 1 12
? 5 10
* 10 13
* 3 5
? 3 6
*/