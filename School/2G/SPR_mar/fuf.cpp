// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h> 
using namespace std; 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

bool prime(int n){  
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
   
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

ll funkcja(ll n){ 
    if(prime(n)){
        return n-1;
    }

    ll result = n;  

    for(ll p = 2; p * p <= n; ++p){ 
        if (n % p == 0){ 
            while (n % p == 0) 
                n /= p; 
                  
            result -= result / p; 
        } 
    } 

    if (n > 1) 
        result -= result / n; 
          
    return result; 
} 
   
int main(){
    fastio;
    ll n; 
    cin >> n;
    cout << funkcja(n);
} 