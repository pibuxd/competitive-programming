// Generator that randomizes numbers on an interval
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// @return random int in the range of (a, b)
int ran_int(int a, int b){
  return a + rand()%(b - a + 1);
}

// @return random string
string ran_str(int n, int len){
  string ran = "";
  for(int i = 0; i < n; i++) 
    ran += (int)'a' + (rand() % len);

  return ran;
}

// @return random vector with int in the range of (a, b)
vector<int> ran_vec(int n, int a, int b){
  vector<int> ran(n, 0);
  generate(ran.begin(), ran.end(), [a, b](){ return ran_int(a, b); });

  return ran;
}

// @return random neighborhood list of tree with n nodes, n-1 edges and 1 as root
vector<vector<int>> ran_tree(int n){
  vector<vector<int>> G(n+1);
  vector<int> parents(n+1);
  
  parents[1] = 1;
  for(int i = 2; i <= n; i++){
    while(parents[i] == 0 || parents[i] == i || !parents[parents[i]])
      parents[i] = ran_int(1, n);

    G[i].push_back(parents[i]);
  }

  return G;
}

void init_Seed(){
  int seed;
  cin >> seed;
  srand(seed);
}

int main(){
  fastio;
  init_Seed();

  vector<int> v = ran_vec(3, 4, 9);
  int x = ran_int(5, 10);
  string s = ran_str(6, 3);
  vector<vector<int>> G = ran_tree(10);

  cout << "\n";
  for(int i : v)
    cout << i << " ";
  cout << "\n\n";

  cout << x << "\n\n"; 
  cout << s << "\n\n";

  // print tree
  cout << G.size()-1 << "\n";
  for(int i = 1; i <= G.size()-1; i++)
    for(int node : G[i])
      cout << i << " " << node << "\n";
}