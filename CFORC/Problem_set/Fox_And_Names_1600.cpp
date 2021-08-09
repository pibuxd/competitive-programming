#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<string> v;
vector<vector<int>> G;
vector<int> ind;

bool compare_words(string &a, string &b){
	int min_len = min(a.size(), b.size());

	for(int i = 0; i < min_len; i++){
		if(a[i] != b[i]){
			G[a[i]-'a'].push_back(b[i]-'a');
			ind[b[i]-'a']++;
			break;
		}
		else if(a[i] == b[i] && i == min_len-1 && b.size() < a.size())
			return false;
	}
	return true;
}

bool build(){
	for(int i = 1; i < n; i++)
		if(!compare_words(v[i-1], v[i]))
			return false;
	return true;
}

string ans(){
	bool ok = build();
	if(!ok)
		return "Impossible";

	string _ans = "";
	queue<int> Q;

	for(int i = 0; i < 26; i++)
		if(!ind[i])
			Q.push(i);

	while(!Q.empty()){
		int v = Q.front();
		Q.pop();

		_ans += (char)('a'+v);

		for(int x : G[v]){
			ind[x]--;
			if(!ind[x]){
				Q.push(x);
			}
		}
	}

	if(_ans.size() == 26)
		return _ans;
	else
		return "Impossible";
}

int main(){
  fastio;
	cin >> n;
	v.resize(n);
	G.resize(26);
	ind.resize(26);

	for(string &str : v)
		cin >> str;

	cout << ans();
}