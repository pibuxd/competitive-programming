#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<int>> KMR(vector<int>&);

void solve(int n, string& str)  {
	if (n==1) {
		cout << "0\n";
		return;
	}

	/*Suffix list*/

	string scopy = str;
	int s = scopy.size();
	int k=0, l=2;
	vector<int> suff(s);
	vector<vector<int>> kmr;
	vector<int> V(2*s-1);
	vector<pair<pair<int,int>,int>> T;


	if (scopy.size()==1) {
		suff[0] = 0;
	} else {

		for (int i=0;i<s-1;i++) {
			scopy += "#";
		}

		for(int i=0;i<2*s-1;i++) {
			V[i] = scopy[i]-35;
		}

		kmr = KMR(V);

		int ksize=kmr[0].size();
		while(l<s) {
			k++;
			l*=2;
		}
		l/=2;

		for(int j=0;(kmr[k][j+s-l]!=-1) && (j+s-l<ksize);j++){
			T.push_back({{kmr[k][j], kmr[k][j+s-l]}, j});
		}

		sort(T.begin(),T.end());

		for(int j=0;j<suff.size();j++) {
			suff[j] = T[j].second;
		}
	}

	/*LCP*/
	vector<int> tmp(suff.size());
	vector<int> L(suff.size()-1,-1);
	int d=0;

	str += "#";

	for (int i=0;i<tmp.size();i++) {
		tmp[suff[i]]=i;
	}

	for (int i=0;i<tmp.size();i++) {
		int k = tmp[i];
		if(k<L.size()) {
			d = max(0, d-1);
			while (
				(suff[k+d]<str.size()) &&
				(suff[k+1]+d<str.size()) &&
				(str[suff[k]+d]==str[suff[k+1]+d])) {
				d++;
			}
			L[k]=d;
		} else {
			d=0;
		}
	}

	vector<int>K(n);
	for(int i=0;i<K.size();i++) {
		K[suff[i]]=i;
	}

	for(int i=0;i<n;i++) {
		if (K[i]==0)
			cout << L[K[i]] << ' ';
		else if (K[i]==n-1)
			cout << L[K[i]-1] << ' ';
		else
			cout << max(L[K[i]-1], L[K[i]]) << ' ';
	}

	cout << '\n';
}

int main() {
	int iter;
	cin>>iter;

	while (iter--) {
		int n;
		cin>>n;

		string str;
		cin>>str;

		solve(n, str);
	}
}

vector<vector<int>> KMR(vector <int>& A){
	int n = A.size();
	int k = 1, l = 2;
	while(l<=n) {
		k++;
		l *= 2;
	}

	vector<vector<int>> R(k, vector<int>(n,-1));
	R[0] = A;
	l = 1;
	for(int i = 1; i < k; i++){
		vector<pair<pair<int,int>, int>> T;
		for(int j=0;j+l<n&&R[i-1][j+l]!=-1;j++){
			T.push_back(pair<pair<int,int>,int>(pair<int,int>(R[i-1][j],R[i-1][j+l]),j));
		}
		sort(T.begin(),T.end());
		int m = 0;
		R[i][T[0].second] = 0;
		for(int j=1;j<T.size();j++) {
			if(T[j].first != T[j-1].first){
				m++;
			}
			R[i][T[j].second] = m;
		}
		l *= 2;
	}
	return R;
}
