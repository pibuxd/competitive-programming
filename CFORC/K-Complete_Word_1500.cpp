#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

string s;
int n, k;

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    cin >> n >> k >> s;
    int ans = 0;

    vector<vector<char>> occur(k, vector<char>(26));
    for(int i = 0; i < n; i++){
      if(k % 2 == 0){
        if(i%k <= k/2-1)
          occur[i%k][s[i]]++;
        else
          occur[k - (i%k) - 1][s[i]]++;
      } else{
        if(i%k <= k/2+1)
          occur[i%k][s[i]]++;
        else
          occur[k - (i%k) - 1][s[i]]++;
      } 
    }

    int d = n/k;
    for(int i = 0; i < k; i++){
      int maxi = *max_element(occur[i].begin(), occur[i].end());
      ans += n - maxi;
    }

    cout << ans << "\n";
  }
}

//0 1 2 3 4 5 6
//a b c d c b a