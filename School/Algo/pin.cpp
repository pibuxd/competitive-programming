#include<bits/stdc++.h>
using namespace std;

void clearStack(stack<int> &S){
  while(!S.empty())
    S.pop();
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  stack<int> S;
  int p, ans = 0;

  for(int i = 0; i < n; i++){
    cin >> p;
    if(p == 0){
      if(S.size() > ans)
        ans = S.size();
      clearStack(S);
    }
    else
      S.push(p);
  }
  if(!S.empty())
    if(S.size() > ans)
      ans = S.size();

  cout << ans;
}
