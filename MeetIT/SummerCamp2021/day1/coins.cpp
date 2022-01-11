#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a, b;
  cin >> a >> b;
  
  if(a > b)
    swap(a, b);

  long long x = b / a;
  
  if(b % a == 0){
    cout << "Yes";
    return 0;
  }

  long long z = x + 1;
  
  if(z < (z*a)-b+1){
    cout << "No";
    return 0;
  }
  cout << "Yes";
}