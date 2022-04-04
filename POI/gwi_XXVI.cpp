// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

const int MAXI = 1e6+1;
int n, start, sum = 0, strike = -1, minimumDiff = MAXI, last, now, curr, l, r, L, R;
bool raz = 0;
vector<int> sequence;

void initData(){
  cin >> n >> start;
  cin >> L >> R;
  curr = start;
  l = 1; r = n;
}

int main(){
  initData();

  if(L > R){
    last = 0;
  } else{
    last = 1;
  }

  for(int i = 1; i < n; i++){
    if(i > 1){
      cin >> L >> R;
    }
    sum += min(L, R);

    if(R > L){
      now = 1;

      if(now != last){ // zmiana skretu
        if(!raz){
          if(strike < start){
            l = strike + 1;
          } else{
            l = start;
            r = strike - start - 1;
            sum += minimumDiff;
          }
          raz = true;

        } else{
          l += strike - 1;
        }

        minimumDiff = MAXI;
        last = now;

      } else{
        minimumDiff = min(R - L, minimumDiff);
        strike++;
      }

    } else{
      now = 0;
      
      if(now != last){ // zmiana skretu
        if(!raz){
          if(strike <= n - start){
            r -= strike;
          } else{
            r = start;
            r = strike - start - 1;
            sum += minimumDiff;
          }
          raz = true;

        } else{
          r -= strike + 1;
        }

        minimumDiff = MAXI;
        last = now;

      } else{
        minimumDiff = min(L - R, minimumDiff);
        strike++;
      }
      
    }
  }

  cout << sum << '\n';
}