#include <bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(0);
int
 a, b, c, d, x, y, z, m, eq; cin >> a >> b >> c >> d;
x = a * b; y = c * d; z = 1/y; m = 1000000000+696969;
eq = (((x % m) * (z % m))) % m;
cout << (((a*b)/(c*d)) % (1000000000+696969)) << endl << eq;
}
