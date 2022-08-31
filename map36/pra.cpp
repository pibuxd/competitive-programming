#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define int long long
#define M1 ((long long)1e9+2139)
#define M2 ((long long)1e9+123)
#define P1 ((long long)23)
#define P2 ((long long)31)

int n, k;
vector<int> hs1, hs2, p1, p2;
vector<char> S;
vector<vector<int>> ids;

int h1(int l, int r){
  return (hs1[r] - (hs1[l-1]) + 2*M1) % M1;
}

int h2(int l, int r){
  return (hs2[r] - (hs2[l-1]) + 2*M2) % M2;
}

bool check(int d){
	vector<pair<int, int>> v;

  for(int lit = 0; lit < 26; lit++){
    for(int i = 0; i < ids[lit].size(); i++){
      if(ids[lit][i]+d-1 > n)
        break;

      int currh1 = (h1(ids[lit][i], ids[lit][i]+d-1)*
										p1[(n-d+1)-ids[lit][i]])%M1;
      int currh2 = (h2(ids[lit][i], ids[lit][i]+d-1)*
										p2[(n-d+1)-ids[lit][i]])%M2;
			v.push_back({currh1, currh2});
		}
  }

	sort(v.begin(), v.end());
	int licz = 1;
	for(int i = 0; i < v.size(); i++){
		if(i+1 < v.size() && v[i] == v[i+1]){
			licz++;
		} else{
			if(licz >= k) return true;
			licz = 1;
		}
	}
  return false;
}

signed main(){
  fastio;
  cin >> n >> k;

  S.resize(n+1);
  hs1.resize(n+1);
  hs2.resize(n+1);
  p1.resize(n+1);
  p2.resize(n+1);
  ids.resize(27);

  p1[0] = p2[0] = 1;
  for(int i = 1; i <= n; i++)
    p1[i] = (p1[i-1] * P1)%M1,
    p2[i] = (p2[i-1] * P2)%M2;
  
  for(int i = 1; i <= n; i++){
    cin >> S[i];
    ids[S[i] - 'a'].push_back(i);
    hs1[i] = (hs1[i-1] + (S[i]*p1[i])%M1 + M1)%M1;
    hs2[i] = (hs2[i-1] + (S[i]*p2[i])%M2 + M2)%M2;
  }
  
  int l = 1, r = n, ans = -1;
  while(l <= r){
    int m = (l+r)/2;
    if(check(m))
      ans = m, l = m+1;
    else
      r = m-1;
  }

  cout << ans << "\n";
  // cout << check(3) << "\n";
  // cout << (h1(4, 6)*p1[5])%M1 << " " << (h2(4, 6)*p2[5])%M2 << "\n";
  // cout << (h1(7, 9)*p1[2])%M1 << " " << (h2(7, 9)*p2[2])%M2 << "\n";
}