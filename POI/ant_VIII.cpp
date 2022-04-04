// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

signed main(){
  fastio;
  int n;
  cin >> n;

  vector<array<int, 2>> sus;

  for(int a = 0, aa = 1; a <= 10; a++, aa *= 2) // 2
    for(int b = 0, bb = 1; b <= a; b++, bb *= 3) // 3
      for(int c = 0, cc = 1; c <= b; c++, cc *= 5) // 5
        for(int d = 0, dd = 1; d <= c; d++, dd *= 7) // 7
          for(int e = 0, ee = 1; e <= d; e++, ee *= 11) // 11
            for(int f = 0, ff = 1; f <= e; f++, ff *= 13) // 13
              for(int g = 0, gg = 1; g <= f; g++, gg *= 17) // 17
                for(int h = 0, hh = 1; h <= g; h++, hh *= 19) // 19
                  for(int i = 0, ii = 1; i <= h; i++, ii *= 23){ // 23
                    int S = (a+1)*(b+1)*(c+1)*(d+1)*(e+1)*(f+1)*(g+1)*(h+1)*(i+1);
                    int SS = (aa)*(bb)*(cc)*(dd)*(ee)*(ff)*(gg)*(hh)*(ii);
                    if(S <= 1536 && SS > 0 && SS <= n)
                      sus.push_back({SS, S});
                  }
  
  sort(sus.begin(), sus.end());
  
  int mx = 0;
  vector<int> anty;
  for(auto x : sus)
    if(x[1] > mx){
      anty.push_back(x[0]);
      mx = x[1];
    }

  auto l = upper_bound(anty.begin(), anty.end(), n);
  l--;
  cout << *l;
}