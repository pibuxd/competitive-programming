// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// bledna odpowiedz (nie testowalem)
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long LOG;
unordered_map<long long, long long> kolejnosc;
vector<long long> in_1; // vector<node x> "+"
vector<pair<pair<long long, long long>, long long>> in_2; // vector<pair<pair<node a, node b>, kolej>> "?"
map<long long, pair<long long, long long>> M; // map<node, pair<node l, node r>> GRAPH
unordered_map<long long, vector<long long>> up;
unordered_map<long long, long long> depth;

void dfs(long long v){
  if(M[v].first){
    long long node_1 = M[v].first;
    up[node_1].resize(LOG);
    depth[node_1] = depth[v] + 1;
    up[node_1][0] = v;
    
    for(long long i = 1; i < LOG; i++)
      up[node_1][i] = up[up[node_1][i-1]][i-1];
    
    dfs(node_1);
  }

  if(M[v].second){
    long long node_2 = M[v].second;
    up[node_2].resize(LOG);
    depth[node_2] = depth[v] + 1;
    up[node_2][0] = v;
    
    for(long long i = 1; i < LOG; i++)
      up[node_2][i] = up[up[node_2][i-1]][i-1];
    
    dfs(node_2);
  }
}

long long lca(long long a, long long b){
  if(depth[a] < depth[b])
    swap(a, b);
  long long k = depth[a] - depth[b];

  for(long long i = 0; i < LOG; i++)
    if((k >> i) & 1)
      a = up[a][i];

  if(a == b)
    return a;

  for(long long i = LOG - 1; i >= 0; i--){
    if(up[a][i] != up[b][i]){
      a = up[a][i];
      b = up[b][i];
    }
  }

  return up[a][0];
}

void m_insert(long long x){
  M[x] = {0, 0};
  auto temp = M.find(x);
  auto _temp = temp;

  auto &curr = temp;
  _temp--;
  auto &left = _temp;
  temp++;
  auto &right = temp;

  auto begin = M.begin();
  auto end = M.end();
  auto dist_begin = distance(begin, curr);
  auto dist_end = distance(curr, end);

  //cout << "KEK: " << x << ",," << dist_begin << " " << dist_end << " " << M.begin()->first << "\"";
  if(dist_begin > 1 && dist_end > 0){
    if(!left->second.second){
      left->second.second = x;
      //cout << "JD1 ";
    } else{
      right->second.first = x;
      //cout << "JD2 ";
    }
  } else if(dist_begin == 1){
    right->second.first = x;
    //cout << "JD3 ";
  } else if(dist_end == 0){
    left->second.second = x;
    //cout << "JD4 ";
  }
}

long long sum_of_path(long long a, long long b, long long lc){
  long long sum_a = 0;
  while(a != lc){
    sum_a += a;
    a = up[a][0];
  }
  long long sum_b = 0;
  while(b != lc){
    sum_b += b;
    b = up[b][0];
  }

  return sum_a + sum_b + lc;
}

int main(){
  fastio;
  long long n;
  cin >> n;
  unordered_map<long long, long long> _kolejnosc;
  //cout << "\n";
  for(long long i = 0; i < n; i++){
    char c;
    cin >> c;
    if(c == '+'){
      long long x;
      cin >> x;                    
      in_1.push_back(x);
      _kolejnosc[x] = i+1;
    } else{
      long long a, b;
      cin >> a >> b;
      in_2.push_back({{a, b}, i+1});
    }
  }

  LOG = ceil(log2(n)) + 1; // 1e6 = MAX n
  long long start = in_1[0];
  up[start] = vector<long long>(LOG);
  up[start][0] = 0;
  up[0] = vector<long long>(LOG);
  kolejnosc[start] = _kolejnosc[start];
  M[start] = {0, 0};
  depth[start] = 0;

  for(long long i = 1; i < in_1.size(); i++){
    if(kolejnosc[in_1[i]]) continue; // aby nie doublowac
    kolejnosc[in_1[i]] = _kolejnosc[in_1[i]];
    m_insert(in_1[i]);
  }

  /*
  cout << "\n";
  for(auto x : M){
    cout << x.first << ": " << x.second.first << ", " << x.second.second << "\n";
  }
  */

  dfs(start);
  //cout << "\n";

  //cout << "LCA: " << lca(3, 8) << "\n";

  for(long long i = 0; i < in_2.size(); i++){
    long long a = in_2[i].first.first;
    long long b = in_2[i].first.second;
    
    if(kolejnosc[a] && kolejnosc[b]){
      if(kolejnosc[a] < in_2[i].second && kolejnosc[b] < in_2[i].second)
        cout << sum_of_path(a, b, lca(a, b)) << "\n";
      else
        cout << "NIE\n";
    }
    else
        cout << "NIE\n";
  }
}