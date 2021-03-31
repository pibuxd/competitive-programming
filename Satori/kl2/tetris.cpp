#include <bits/stdc++.h>
using namespace std;

constexpr int base = 1 << 20;
constexpr int INF = 1<<30;
int tree[base * 2];
int star[base * 2];

void push(int x) {
    tree[x * 2] += star[x];
    tree[x * 2 + 1] += star[x];
    star[x * 2] += star[x];
    star[x * 2 + 1] += star[x];
    star[x] = 0;
}

void add(int x, int qFrom, int qTo, int from, int to, int value) {
    if (qFrom <= from && to <= qTo) {
        tree[x] += value;
        star[x] += value;

        return;
     }

    if (star[x] != 0) {
        push(x);
    }

    int avg = (from + to) / 2;

    if (qFrom <= avg)
        add(x * 2, qFrom, qTo, from, avg, value);
    if (avg < to)
        add(x * 2, qFrom, qTo, avg + 1, to, value);

    tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
}

int read(int x, int qFrom, int qTo, int from, int to) {
    if (qFrom <= from && to <= qTo)
        return tree[x];
    if (star[x] != 0)
        push(x);

    int avg = (from + to) / 2;
    int result = -INF;

    if (qFrom <= avg)
        result = max(result, read(x * 2, qFrom, qTo, from, avg));
    if (avg < qTo)
        result = max(result, read(x * 2 + 1, qFrom, qTo, avg + 1, to));

    tree[x] = max(tree[x * 2], tree[x * 2 + 1]);

    return result;
}

int main() {
    int n,k;
    cin>>k>>n;

    unsigned int offset2 = k;
    offset2--;
    offset2 |= offset2 >> 1;
    offset2 |= offset2 >> 2;
    offset2 |= offset2 >> 4;
    offset2 |= offset2 >> 8;
    offset2 |= offset2 >> 16;
    offset2++;

    for(int i=0;i<n;i++) {
        int a,b;
        cin >> b >> a;
        b--;
        a++;
        //int m = read(1, k, a, a+b, 1);
        add(1, 0, k, a, a+b, 1);
    }

    for(int i=1; i < k; i++){
        cout << tree[i] << '\n';
    }
}