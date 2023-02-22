#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n;
string s;

signed main(){
  fastio;
  cin >> s;
  n = s.size();
  int P = 0;
  
  for(char c : s){
    int l = (char)c-'0';
    P += l;
  }
  string res = "";
  int przes = 0;
  for(int i = 1; i <= n; i++)
    res += (char)((char)((P+przes)%10) + '0'), przes = (P+przes)/10;
  while(przes){
    res += (char)((char)(przes%10) + '0');
    przes /= 10;
  }
  
  reverse(all(res));
  cout << res << "\n";
}
