// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(0);
int n; string N, sx, sn; char s;
cin >> n;
for(int it = 0, max = 0, min = 0, sum = 0, w = 0, w2 = 0, mx = 0, mn = 0; it < n; it++, max = 0, min = 0, sum = 0, mx = 0, mn = 0){
    cin >> N;
    for(int i = 0; i < N.size(); i++){
      if(N[i] == 'a' || N[i] == 'e' || N[i] == 'i' || N[i] == 'o' || N[i] == 'u' || N[i] == 'y'){ //j
        sum++; w = 3;
      }
      else if(N[i] == 'A' || N[i] == 'E' || N[i] == 'I' || N[i] == 'O' || N[i] == 'U' || N[i] == 'Y'){ //J
        sum++; w = 1;
      }
      else if(N[i] > 64 && N[i] < 91){ //C
        sum++; w = 2;
      }
      else if(N[i] > 96 && N[i] < 123){ //c
        sum++; w = 4;
      }
      if(w != w2 && i > 0){
        if(sum > max || (sum > max && mx > w)){
          max = (sum - 1); mx = w;
        }
        else if(sum < min || (sum < min && mn > w)){
          min = (sum - 1); mn = w;
        }
        sum = 0;
      }
      w2 = w;
    }
    if(mx=1) sx="JASNE"; if(mx=2) sx="CIEMNE"; if(mx=3) sx="jasne"; if(mx=4) sx="ciemne";
    if(mn=1) sn="JASNE"; if(mn=2) sn="CIEMNE"; if(mn=3) sn="jasne"; if(mn=4) sn="ciemne";
    cout << max << " " << sx << '\n' << min << " " << sn << '\n';
 }
}
