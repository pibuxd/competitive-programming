// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Koc {
  int odl, start, end, pow; 
  pair<int, int> ul;
};

int n, dlg, z;
priority_queue<Koc> PQ;

bool pow2(int num){ 
  if((num != 0) && ((num &(num - 1)) == 0)) return true;
  return false; 
}

int maxFraction(pair<int, int> x, pair<int, int> y){ 
  int a = x.first; 
  int b = x.second; 
  int c = y.first; 
  int d = y.second; 
  int Y = a * d - b * c; 

  if(Y == 0) return 0;

  return (Y > 0) ? 1 : -1;
}

pair<int, pair<int, int>> reduceFraction(pair<int, pair<int, int>> ulamek){
  int d;
  d = __gcd(ulamek.second.first, ulamek.second.second); 

  ulamek.second.first = ulamek.second.first / d; 
  ulamek.second.second = ulamek.second.second / d; 
  return ulamek;
}

bool compare(pair<int, int> a, pair<int, int> b){
  auto maximum = maxFraction(a, b);

  if(maximum == 1) return true;
  else if(maximum == -1) return false;

  else if(maximum == 0){
    if(a.first > b.first){
      
    } else if(a.first < b.first){
      
    } else{
      if(a.second > b.second){
        
      } else if(a.second < b.second){

      }
    }
  }
} 

int main(){
  fastio;
  cin >> n >> dlg >> z;

  int last = 0, a;
  cin >> a;

  for(int i = 2; i <= n; i++){
    cin >> a;
    PQ.push({a-last, last, a, 1});
  }

  int input, licz = 1;
  cin >> input;

  for(pair<int, pair<int, int>> ans; z--; licz++){
    Koc k = PQ.top();
    
    if(pow2(k.pow)){
      ans = {k.start + k.odl / 2, {k.ul.first, k.ul.second+2}};
    }
    if(licz == input){
      ans = reduceFraction(ans);
      cout << ans.second.first << '/' << ans.second.second << '\n';
      cin >> input;
    }
  }
}