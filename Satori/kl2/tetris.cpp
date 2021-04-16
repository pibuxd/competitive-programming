/**
 * * lazy propagation segment tree
 * * range set value, range maximum
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MAX_tree_size = 1<<21;
int tree[MAX_tree_size];
int lazy[MAX_tree_size];

int nearest_2pot(int x) {
 int ans;

 ans = 1;
 while(ans < x)
    ans <<= 1;

 return ans;
}

void push(int v){
 if(lazy[v] == 0)
    return;
 tree[2*v] = lazy[v];
 tree[2*v + 1] = lazy[v];
 lazy[2*v] = lazy[v];
 lazy[2*v + 1] = lazy[v];
 lazy[v] = 0;
}

int query_max(int p, int k, int v, int a, int b){
 if (a > k || b < p)
     return 0;

 if(a >= p && b <= k)
     return tree[v];

 push(v);
 return max(query_max(p, k, 2*v, a, (a + b)/2), query_max(p, k, 2 * v + 1, (a + b)/2+1, b));
}

void update_set(int p, int k, int v, int a, int b, int value){
 if(a > k || b < p)
     return;

 if(a >= p && b <= k){
     tree[v] = value;
     lazy[v] = value;
     return;
 }

 push(v);
 update_set(p, k, 2*v, a, (a + b) / 2, value);
 update_set(p, k, 2*v + 1, (a + b) / 2 + 1, b, value);
 tree[v] = max(tree[2*v], tree[2*v + 1]);
}

int main() {
 fastio;

 int m, n;
 cin >> n >> m;

 int temp = nearest_2pot(n);
 int tree_size = 2 * temp;

 for(int i = 0, kolcek_start, kolcek_end, kolek_len; i < m; i++){
    cin >> kolek_len >> kolcek_start;
    kolek_len--;
    kolcek_end = kolcek_start + kolek_len;
    int max_on_segment = query_max(kolcek_start, kolcek_end, 1, 0, temp-1);
    update_set(kolcek_start, kolcek_end, 1, 0, temp-1, max_on_segment + 1);	
 }
 
 cout << tree[1] << "\n";
}