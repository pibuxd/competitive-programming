#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define ll long long
#define int long long

struct node {
    int val = 0;
    ll pref = 0;
};

int n, q, NO = -1, P = 1e8, N = 1e9+P;
vector<int> ltab;
map<int, node> M;

void addpref(ll val, int idx){
    for(; idx <= N; idx += idx & (-idx))
        M[idx].pref += val;
}

void addpref(ll val, int l, int r){
    addpref(val, l);
    addpref(-val, r+1);
}

ll sumpref(int idx){
    ll res = 0;
    for(; idx >= 1; idx -= idx & (-idx))
        res += M[idx].pref;
    return res;
}

void addval(int val, int idx){
    for(; idx <= N; idx += idx & (-idx))
        M[idx].val += val;
}

int sumval(int idx){
    int res = 0;
    for(; idx >= 1; idx -= idx & (-idx))
        res += M[idx].val;
    return res;
}

int sumval(int l, int r){
    return sumval(r) - sumval(l-1);
}

int bs(int x, int o){
    int l = 1, r = N, ans = 1;
    while(l <= r){
        int mid = (l+r)/2;
        if(sumpref(mid) + mid <= x-o)
            l = mid+1, ans = mid;
        else
            r = mid-1;
    }
    return ans;
}

int sum(int a, int b){
   // cout << bs(a, 1)-P << " " << bs(b, 0)-P << " =  ";
    return sumval(1, bs(b, 0)) - sumval(1, bs(a, 1));
}

void podlej(int x){
    int l = 1, r = N, pkt = 1;
    while(l <= r){
        int mid = (l+r)/2;
        int sv = sumval(1, mid);

        if(sv <= x)
            l = mid+1, pkt = mid;
        else{
            int svmid = sumval(mid, mid);
            int BS = bs(mid+sumpref(mid), 1);
            //cout << mid-P << " " << sv << " " << svmid << " " << BS - P << "\n";
            if(sv - svmid <= x){
                int dif = sv - x; 
                addval(dif, BS);
                addval(-dif, mid);
                pkt = mid;
                //cout << "F ";
                break;

            } else
                r = mid-1;
        }
    }
    //cout << "podlane " << pkt-P << "\n";
    addpref(1, 1, pkt);
}

signed main(){
    fastio;
    cin >> n >> q;
    ltab.resize(n+1);

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ltab[i] = x + P;
    }
    sort(all(ltab));
    ltab.push_back(NO);

    int lastcnt = 0, last = NO;
    for(int i = 1; i <= n+1; i++){
        if(ltab[i] != last){
            if(last != NO)
                addval(lastcnt, last);
            last = ltab[i];
            lastcnt = 0;
        }
        lastcnt++;
    }

    while(q--){
        string oper; cin >> oper;
        if(oper[0] == 'p'){
            int x; cin >> x; 
            podlej(x);
        } else{
            int a, b; cin >> a >> b;
            a += P, b += P;
            cout << sum(a, b) << "\n";
        }
    }
}
