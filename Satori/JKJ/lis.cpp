#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int t; cin >> t;

  while(t--){
    string A[100];
    cin >> A[0];
    int y = 1;
    for(int i = 1; cin.get() != '\n'; i++, y++){
      cin >> A[i];
    }

    map<string, int> B;
    int i = 1, x = 0;

    while(true){
      string a, b, c;
      cin >> a >> b;

      if(b == "say?")
        goto next;

      cin >> c;
      B[c] = 1;
      i++; x++;
    }

  next:
    for(int i = 0; i < y; i++){
      if(B[A[i]] == 0)
        cout << A[i] << ' ';
    }
    cout << '\n';
  }
}
