#include <bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(0);
long long n, a, b, sr[1000001], sn[1000001], sum_pref[1000001], N = 0, R = 0, sum; cin >> n;
char S[1000001]; sum_pref[0] = 0;
  for(int i = 0; i < n; i++) cin >> S[i];
  for(int i = 0; i < n; i++){
    if(S[i] == 'N') {N++; sum_pref[i+1] = sum_pref[i] + R;}
    else{R++; sum_pref[i+1] = sum_pref[i];}
    sr[i] = R; sn[i] = N;
  } cin >> n;
  for(int i = 0; i < n; i++){ cin >> a >> b;
    sum = sum_pref[b] - sum_pref[a] - (sr[a-2] * (sn[b-1] - sn[a-1]));
cout << sum << '\n';
  }
}
