#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
#define LL long long

LL fastPow(LL x, LL y){
 LL powHALF;
 LL ans;

 if(y == 0)
    return 1;

 powHALF = fastPow (x, y / 2);
 ans = powHALF * powHALF;
 ans %= mod;

 if((y % 2) == 1 ){
    ans *= x;
    ans %= mod;
 }
 return ans;
}

int main(){
 int T, n;
 LL ans;

 cin >> T;

 for(int i = 1; i <= T; i++){
    cin >> n;
    ans = fastPow(n,n);
    ans -= n - mod;
    ans %= mod;
    cout << ans << endl;
 }
}
