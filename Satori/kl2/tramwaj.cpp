#include "bits/stdc++.h"
using namespace std;
// Kruskals

int V, E;

void readGraph(vector<pair<int, pair<int, int>>> &Edge){
  cin >> V >> E;
  for(int i = 0, a, b, c; i < E; i++){
    cin >> a >> b >> c;
    Edge.push_back({c, {a, b}});
  }
}

void minimumSpanningTree(const vector<pair<int, pair<int, int>>> &Edge){
  long long sum = 0;
  vector<int> parent(V+1);

  for(auto x : Edge){
    int a = x.second.first, aa = x.second.first;
    while(parent[a] > 0){
      a = parent[a];
    }
    
    int b = x.second.second, bb = x.second.second;
    while(parent[b] > 0){
      b = parent[b];
    }
    
    if(a != b){
      sum += x.first;
      parent[a] = b;
    }
    
    // path compression
    while(aa != a){
      int next = parent[aa];
      parent[aa] = a;
      aa = next;
    }

    while(bb != b){
      int next = parent[bb];
      parent[bb] = b;
      bb = next;
    }
  }

  cout << sum << '\n';
}

int main(void){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  while(T--){
    vector<pair<int, pair<int, int>>> Edge;
    readGraph(Edge);
    sort(Edge.begin(), Edge.end());
    minimumSpanningTree(Edge);
  }
}
