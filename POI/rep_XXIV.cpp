// not working
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(x) x.begin(), x.end()

int n, X;
vector<int> a, r, x;
set<int> dif;
unordered_map<int, array<int, 2>> wsp;

signed main(){
  fastio;
  cin >> n;
  x.assign(n, 0);
  for(int &i : x) cin >> i;

  X = *max_element(all(x));
  a.assign({0, 1, 2});
  r.assign({0, 1, 2});
  dif.insert(1);
  wsp[1] = {2, 1};
  for(int i = 3; a[i-1] <= X; i++){
    a.push_back(0);
    r.push_back(0);

    if(i % 2 != 0)
      a[i] = 2 * a[i-1];
    else
      a[i] = a[i-1] + r[i-1];

    for(int j = 1; j < i; j++){
      dif.insert(a[i] - a[j]);
      wsp[a[i] - a[j]] = {i, j};
    }
    r[i] = r[i-1];
    while(dif.count(r[i]))
      r[i]++;
  }

  for(int i : x){
    if(wsp[i][0])
      cout << wsp[i][0] << " " << wsp[i][1] << "\n";
    else{
      auto it = dif.lower_bound(i);
      it--;
      int ile = distance(dif.begin(), it) + 1;
      cout << ile << "\n";

      auto nrit = lower_bound(all(a), i);
      int nr = distance(a.begin(), nrit);
      cout << nr << "\n";
      
      int w = 2*(i - ile) + nr + nr%2;
      cout << w << " " << w-1 << "\n";
    }
  }
}

/*
1 ->   : 1  1
2 -> 1 : 2  2
3 -> 3 2  : 4  4
4 -> 7 6 4  : 8  5
5 -> 15 14 12 8  : 16  5
6 -> 20 19 17 13 5  : 21  9
7 -> 41 40 38 34 26 21  : 42  9
8 -> 50 49 47 43 35 30 9  : 51  10
9 -> 101 100 98 94 86 81 60 51  : 102  10
10 -> 111 110 108 104 96 91 70 61 10  : 112  11
11 -> 223 222 220 216 208 203 182 173 122 112  : 224  11
12 -> 234 233 231 227 219 214 193 184 133 123 11  : 235  16
13 -> 469 468 466 462 454 449 428 419 368 358 246 235  : 470  16
14 -> 485 484 482 478 470 465 444 435 384 374 262 251 16  : 486  18
15 -> 971 970 968 964 956 951 930 921 870 860 748 737 502 486  : 972  18
16 -> 989 988 986 982 974 969 948 939 888 878 766 755 520 504 18  : 990  22
17 -> 1979 1978 1976 1972 1964 1959 1938 1929 1878 1868 1756 1745 1510 1494 1008 990  : 1980  22
18 -> 2001 2000 1998 1994 1986 1981 1960 1951 1900 1890 1778 1767 1532 1516 1030 1012 22  : 2002  23
19 -> 4003 4002 4000 3996 3988 3983 3962 3953 3902 3892 3780 3769 3534 3518 3032 3014 2024 2002  : 4004  23
20 -> 4026 4025 4023 4019 4011 4006 3985 3976 3925 3915 3803 3792 3557 3541 3055 3037 2047 2025 23  : 4027  24
21 -> 8053 8052 8050 8046 8038 8033 8012 8003 7952 7942 7830 7819 7584 7568 7082 7064 6074 6052 4050 4027  : 8054  24
22 -> 8077 8076 8074 8070 8062 8057 8036 8027 7976 7966 7854 7843 7608 7592 7106 7088 6098 6076 4074 4051 24  : 8078  25
23 -> 16155 16154 16152 16148 16140 16135 16114 16105 16054 16044 15932 15921 15686 15670 15184 15166 14176 14154 12152 12129 8102 8078  : 16156  25
24 -> 16180 16179 16177 16173 16165 16160 16139 16130 16079 16069 15957 15946 15711 15695 15209 15191 14201 14179 12177 12154 8127 8103 25  : 16181  27
25 -> 32361 32360 32358 32354 32346 32341 32320 32311 32260 32250 32138 32127 31892 31876 31390 31372 30382 30360 28358 28335 24308 24284 16206 16181  : 32362  27
26 -> 32388 32387 32385 32381 32373 32368 32347 32338 32287 32277 32165 32154 31919 31903 31417 31399 30409 30387 28385 28362 24335 24311 16233 16208 27  : 32389  28
27 -> 64777 64776 64774 64770 64762 64757 64736 64727 64676 64666 64554 64543 64308 64292 63806 63788 62798 62776 60774 60751 56724 56700 48622 48597 32416 32389  : 64778  28
28 -> 64805 64804 64802 64798 64790 64785 64764 64755 64704 64694 64582 64571 64336 64320 63834 63816 62826 62804 60802 60779 56752 56728 48650 48625 32444 32417 28  : 64806  29
29 -> 129611 129610 129608 129604 129596 129591 129570 129561 129510 129500 129388 129377 129142 129126 128640 128622 127632 127610 125608 125585 121558 121534 113456 113431 97250 97223 64834 64806  : 129612  29
*/
