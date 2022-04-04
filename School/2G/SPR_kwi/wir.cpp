// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void push(char ch, int &a, int &b, int &c, int &d, int &e, int &f){
  if(ch == 'A'){
      a++;
    } else if(ch == 'B'){
      b++;
    } else if(ch == 'C'){
      c++;
    } else if(ch == 'D'){
      d++;
    } else if(ch == 'E'){
      e++;
    } else if(ch == 'F'){
      f++;
    }
}

void pop(char ch, int &a, int &b, int &c, int &d, int &e, int &f){
  if(ch == 'A'){
      a--;
    } else if(ch == 'B'){
      b--;
    } else if(ch == 'C'){
      c--;
    } else if(ch == 'D'){
      d--;
    } else if(ch == 'E'){
      e--;
    } else if(ch == 'F'){
      f--;
    }
}

bool wir(int a, int b, int c, int d, int e, int f){
  if(a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 1){
    return true;
  } else{
    return false;
  }
}

int solve(string s){
  int ans = 0;
  int a, b, c, d, e, f;
  a = b = c = d = e = f = 0;

  if(s.size() < 6) return 0;

  for(int i = 0; i < 6 && i < s.size(); i++){
    push(s[i], a, b, c, d, e, f);
  }
  if(wir(a, b, c, d, e, f)){
    ans++;
  }

  for(int i = 6; i < s.size(); i++){
    char last = s[i-6], next = s[i];
    pop(last, a, b, c, d, e, f);
    push(next, a, b, c, d, e, f);

    if(wir(a, b, c, d, e, f)){
      ans++;
    }
  }

  return ans;
}

int main(){
  fastio;
  int t; cin >> t;

  while(t--){
    string s; cin >> s;
    cout << solve(s) << "\n";
  }
}