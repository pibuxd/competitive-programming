// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int potega(int a, int n){
    if(a==0)
        return 0;
    if(n==1)
        return a;
    if(n==0)
        return 1;
    return potega(a, n-1)*a;
}

int suma(int tab[], int n){
    if(n==1)
        return tab[0];
    return suma(tab, n-1) + tab[n-1];
}

void rev(int n){
    int x; cin >> x;
    if(n==1){
        cout<<x;
        return;
    }
    rev(n-1);
    cout<<x;
}

int main(){
    int a, n; cin >> a >> n;
    cout << potega(a, n) << '\n';

    int tab[3] = {1, 2, 3};
    cout << suma(tab, 3) << '\n';

    rev(4);
}
