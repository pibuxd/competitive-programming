#include <bits/stdc++.h>
using namespace std;

bool visited[(int)1e5 + 5], on_stack[(int)1e5 + 5];
vector<int> G[(int)1e5 + 5];
vector<int> cycle;
int N, M;

bool dfs(int n) {
	visited[n] = on_stack[n] = true;
	for (int u : G[n]) {
		if(on_stack[u]) {
			cycle.push_back(n);
			on_stack[n] = on_stack[u] = false;
			return true;
		}
		else if(!visited[u]) {
			if(dfs(u)){
				if(on_stack[n]) {
					cycle.push_back(n);
					on_stack[n] = false;
					return true;
				} else {
					cycle.push_back(n);
					return false;
				}
			}
			if(!cycle.empty())
				return false;
		}
	}
	on_stack[n] = false;
	return false;
}
int main(){
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	for (int i = 1; cycle.empty() && i <= N; i++)
		dfs(i);
	if(cycle.empty())
		cout << "IMPOSSIBLE";
	else {
		reverse(cycle.begin(), cycle.end());
		cout << cycle.size() + 1 << "\n";
		for(int n : cycle) cout << n << " ";
		cout << cycle.at(0);
	}
}