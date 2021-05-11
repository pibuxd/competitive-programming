#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)  

void solve(string str){
    int starting_len = str.size();
    string temp = str + '?';
    reverse(str.begin(), str.end());
  
    temp += str;
    int n = temp.length();

    int lps[n];

    fill(lps, lps + n, 0);
  
    for (int i = 1; i < n; i++) {
        int len = lps[i - 1];

        while (len > 0
               && temp[len] != temp[i]) {
            len = lps[len - 1];
        }

        if (temp[i] == temp[len]) {
            len++;
        }
  
        lps[i] = len;
    }
  
    cout << starting_len - temp.substr(0, lps[n - 1]).size();
}

int main(){
    fastio;
    string str; cin >> str;
    reverse(str.begin(), str.end());

    solve(str);
}