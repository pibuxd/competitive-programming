// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * MST -> Kruskals algorithm
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Edge {
  int nr, first, second, weight;

  bool operator < (const Edge& other) const {
    return weight < other.weight;
  }
};

struct MST {
  int n, m;
  vector<Edge> edges;
  vector<int> parent, rank;
  vector<int> is_inserted;

  MST(int _n, int _m) {
    n = _n;
    m = _m;
  }

  void push(Edge edge) {
    edges.push_back(edge);
  }

  void order() {
    sort(edges.begin(), edges.end());
  }

  void make_union(int v) {
    parent[v] = v;
    rank[v] = 0;
  }

  int find_in_union(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_in_union(parent[v]);
  }

  void unite(int a, int b) {
    if(a != b) {
      if(rank[a] < rank[b])
        swap(a, b);
      parent[b] = a;
      if(rank[a] == rank[b])
        rank[a]++;
    }
  }

  void init() {
    order();
    is_inserted.resize(m+1);
    parent.resize(n+1);
    rank.resize(n+1);

    for(int i = 1; i <= n; i++)
      make_union(i);

    for(Edge edge : edges) {
      int v = find_in_union(edge.first);
      int u = find_in_union(edge.second);

      if(v != u) {
        is_inserted[edge.nr] = 1;
        unite(v, u);
      }
    }
  }

  void answer() {
    for(int i = 1; i <= m; i++) {
      if(is_inserted[i]) {
        cout << "TAK\n";
      } else {
        cout << "NIE\n";
      }
    }
  }
};

int main() {
  fastio;
  int n, m;
  cin >> n >> m;

  MST graph(n, m);
  for(int a, b, weight, i = 1; m--; i++) {
    cin >> a >> b >> weight;
    graph.push({i, a, b, weight});
  }

  graph.init();
  graph.answer();
}