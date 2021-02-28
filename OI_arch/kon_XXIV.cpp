#include <bits/stdc++.h>
using namespace std;

void bigJump(int liczba, int start, int odstep, vector<int> &ans, vector<int> &opening, vector<int> &closing){
  opening[start]++;
  closing[start+(liczba-1)*odstep]++;
}

void smallJump(int liczba, int start, int odstep, vector<int> &ans, vector<int> &openieng, vector<int> &closing){
  return;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  const int sqrtN = sqrt(n);
  vector<int> ans(n+1), opening(n+1), closing(n+1); 

  while(k--){
    int liczba, start, odstep;
    cin >> start >> liczba >> odstep;

    if(true){
      bigJump(liczba, start, odstep, ans, opening, closing);
    } else{
      smallJump(liczba, start, odstep, ans, opening, closing);
    }
  }

  for(int i = 1; i <= n; i++){
    cout << ans[i] << ' ';
  }
  cout << "\n\n";

  for(int x : opening){
    cout << x << ' ';
  } cout << '\n';
  for(int x : closing){
    cout << x << ' ';
  } cout << '\n';
}