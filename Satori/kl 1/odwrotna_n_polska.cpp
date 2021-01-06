#include <bits/stdc++.h>
using namespace std;

long long power(int a, int b){
  if(b == 0)
    return 1;
  int mul = a;
  for(int i = 1; i < b; i++){
     a *= mul;
  }
  return a;
}

int main(){ //ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  int modulo = 10007;
  while(t--){
    int n;
    cin >> n;
    stack<int> st;
    int a = 0;

    while(n--){
      string s;
      cin >> s;

      if(s == "+"){
        a = st.top();
        st.pop();
        a += st.top();
        st.pop();
        st.push(a % modulo);
      }

      else if(s == "*"){
        a = st.top();
        st.pop();
        a *= st.top();
        st.pop();
        st.push(a % modulo);
      }

      else if(s == "^"){
        a = st.top();
        st.pop();
        a = (power(a, st.top()) % modulo);
        st.pop();
        st.push(a);
      }

      else{
        st.push(stoi(s));
      }

    }
    cout << '\t' << st.top() << '\n';
  }
}
