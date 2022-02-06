#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void np(int n){
  vector<int> ans(2*n+1);

  int l = 1, r = n, i = 1;

  while(l <= r){
    while(ans[i] != 0)
      i++;
    ans[i] = ans[i+l] = l;

    while(ans[i] != 0)
      i++;
    ans[i] = ans[i+r] = r;

    l++, r--;
  }

  for(int i = 1; i <= 2*n; i++)
    cout << ans[i] << " ";
}

int main(){
  fastio;
  int n;
  cin >> n;

  int m = n%4;
  
  if(m == 2 || m == 3){
    cout << "NIE";
    return 0;
  }

  if(m == 0 || m == 1)
    cout << "TAK\n";

  if(n % 2 == 0){  
    if(n == 4)
      cout << "4 2 3 2 4 3 1 1";
    // else if(n == 5)
    //   cout << "1 1 5 2 4 2 3 5 4 3";
    else if(n == 8)
      cout << "1 1 2 8 2 3 6 7 3 4 5 8 6 4 7 5";
    // else if(n == 9)
    //   cout << "1 1 2 8 2 3 9 7 3 4 6 8 5 4 7 9 6 5";
    else{
      for(int i = 1; i <= n; i++)
        cout << i << " " << i << " ";
    }
  }
  else{
    np(n);
  }
}