#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int n;
  cin >> n;

  while(n--){
    string s;
    cin >> s;
    stack<char> S;

    for(int i = 0; i < s.size(); i++){
      if(s[i] == '('){
        S.push('(');
      }
      if(s[i] == ')' && !S.empty() && S.top() == '('){
        S.pop();
      }
      else if(s[i] == ')' && (!S.empty() &&  S.top() != '(') || (S.empty() && s[i] == ')'))
        goto nie;


      if(s[i] == '{'){
        S.push('{');
      }
      if(s[i] == '}' && !S.empty() &&  S.top() == '{'){
        S.pop();
      }
      else if(s[i] == '}' && (!S.empty() &&  S.top() != '{') || (S.empty() && s[i] == '}'))
        goto nie;


      if(s[i] == '['){
        S.push('[');
      }
      if(s[i] == ']' && !S.empty() &&  S.top() == '['){
        S.pop();
      }
      else if(s[i] == ']' && (!S.empty() && S.top() != '[') || (S.empty() && s[i] == ']'))
        goto nie;
    }

    if(!S.empty()){
      while(!S.empty()){
        if(S.top() == '('){
          cout << ')';
        }
        else if(S.top() == '{'){
          cout << '}';
        }
        else if(S.top() == '['){
          cout << ']';
        }
        S.pop();
      }
      cout << '\n';
    }
    else
      cout << "TAK" << '\n';
    goto end;
    nie:
      cout << "NIE" << '\n';
    end:;
  }
}
