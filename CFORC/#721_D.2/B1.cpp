#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){ fastio;
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    if(n == 1){
      char c; cin >> c;
      if(c == '1') cout << "DRAW\n";
      else cout << "BOB\n";
      continue;
    }

    vector<bool> c1(n/2+1), c2(n/2+1);
    bool m = 0;

    if(n % 2 == 0){
      for(int i = 1; i <= n/2; i++){
        char c; cin >> c;
        if(c == '1') c1[i] = 1;
      }
      for(int i = n/2; i > 0; i--){
        char c; cin >> c;
        if(c == '1') c2[i] = 1;
      }
    } else{
      for(int i = 1; i <= n/2; i++){
        char c; cin >> c;
        if(c == '1') c1[i] = 1;
      }

      char c; cin >> c;
      if(c == '1') m = 1;

      for(int i = n/2; i > 0; i--){
        char c; cin >> c;
        if(c == '1') c2[i] = 1;
      }
    }

    int on = 0, tw = 0; // one to get palindrome, two to get palindrome
    
    if(n % 2 == 0){
      for(int i = 1; i <= n/2; i++){
        if((c1[i] && !c2[i]) || (!c1[i] && c2[i])) on++;
        else if(!c1[i] && !c2[i]) tw++;
      }
    } else{
      for(int i = 1; i <= n/2; i++){
        if((c1[i] && !c2[i]) || (!c1[i] && c2[i])) on++;
        else if(!c1[i] && !c2[i]) tw++;
      }
      if(!m) on++;
    }

    int a = 0, b = 0;
    bool pal, rev = false, at = true, bt = false;

    if(on) pal = false;
    else pal = true;

    while(on || tw){
      if(!rev && !pal){
        if(at){
          at = false;
          bt = true;
        } else{
          bt = false;
          at = true;
        }
        rev = true; 
      } else{
        if(on){
          on--;
        } else if(tw){
          tw--;
          on++;
          if(!pal) pal = true;
          else pal = false;
        }
        if(at){
          a++;
          at = false;
          bt = true;
        } else{
          b++;
          bt = false;
          at = true;
        }
        rev = false;
      }
    }

    if(a < b) cout << "ALICE\n";
    else if(a > b) cout << "BOB\n";
    else cout << "DRAW\n";
  }
}