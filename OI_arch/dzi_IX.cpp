#include <bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(0);
int n, max = 0; cin >> n;
int A[n][n], V[100][100];
  for(int i = 0, it = 0, z = 0; it < n; i++){
    if((i+1) % 5 == 0){ it++; i = 0; }
    cin >> A[i][it];
    if(A[i][it] == 0){
      V[z][it]++
    }
    if(A[i][it] == 0 || i == (n - 2)) z++;
  }

}
