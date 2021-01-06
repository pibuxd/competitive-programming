#include<bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int ruchy, czas_dzialan; cin >> ruchy >> czas_dzialan;
  vector<int> D(ruchy+1);

  for(int i = 1; i <= ruchy; i++)
    cin >> D[i];


  int x, y, ans = 0; cin >> x >> y;
  int i = 0;
  for(int czas = 0, X = 0, Y = 0, it = 1; czas < czas_dzialan; it++){
    if(it%ruchy == 0)
      int i = it;
    else
      int i = it%ruchy;

    if(it%4 == 1){
      Y += D[i];

      if(X == x && (y > (Y-D[i]) && y < Y))
        ans++;
    }
    else if(it%4 == 2){
      X += D[i];

      if(Y == y && (x > (X-D[i]) && x < X))
        ans++;
    }
    else if(it%4 == 3){
      Y -= D[i];

      if(X == x && (y < (Y+D[i]) && y > Y))
        ans++;
    }
    else{
      X -= D[i];

      if(Y == y && (y < (Y+D[i]) && y > Y))
        ans++;
    }

    if(X == x && Y == y)
      ans++;

    czas += D[i] + 1;
  }

  cout << ans;
}
