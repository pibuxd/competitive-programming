#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, currmx;

bool iftake(int x){
  if(x < currmx) return false;
  
  if(x - currmx <= 460){
    currmx = x;
    return true;
  }
  return false;
}

signed main(){
  fastio;
  cin >> n;

  currmx = 0;

  for(int i = 1; i <= n; i++){
    int x; cin >> x;
    cout << iftake(x) << "\n";
  }
}
