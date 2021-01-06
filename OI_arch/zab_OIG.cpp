#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll odl(pair<int, int> *Zb, int a, int b){
	ll x = Zb[a].first - Zb[b].first;
	x *= x;
	ll y = Zb[a].second - Zb[b].second;
	y *= y;

	return x + y;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
	int n, p, g;
	ll s, max = 0, po;
	cin >> n >> p >> s;
	p--;
	s *= s;
	bool cb[n]; //czy był
	pair<int, int> *Zb = new pair<int, int>[n];
	pair<int, int> pom;
	for(int i = 0; i < n; i++){
		cb[i] = false;
		cin >> pom.first >> pom.second;
		Zb[i] = pom;
	}
//BFS
	queue<int> Q;
	Q.push(p);
	cb[p] = true;
	while(!Q.empty()){
		g = Q.front();
		po = odl(Zb, g, p);
		if(po > max)
			max = po;
		for(int i = 0; i < n; i++)
			if(!cb[i])
				if(odl(Zb, g, i) <= s){
					cb[i] = true;
					Q.push(i);
				}
		Q.pop();
	}
	cout << fixed << setprecision(3) << sqrt(max) + sqrt(s) << '\n';
}
