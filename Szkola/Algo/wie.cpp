#include<bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int schodki, ludzie; cin >> schodki >> ludzie;
  vector<int> S(schodki+1), L(ludzie+1);

  for(int i = 1; i <= schodki; i++)
    cin >> S[i];

  for(int i = 1; i <= ludzie; i++){
    cin >> L[i];
    int it = 1, ans = 0;
    while(S[it] < L[i]){
      ans++;
      it++;
    }
    cout << ans << ' ';
  }
}
