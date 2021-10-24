#include<bits/stdc++.h>
using namespace std;

int n;
string S;
vector<string> ans;

int num(int start, int len){;
    return stoi(S.substr(start, len));
}

void foo(int l, int licz, string ip){
    if(l > n-1 || licz > 4)
        return;
    if(l == n-1){
        if(licz == 4){
            ans.push_back(ip);
            return;
        }
        else return;
    }

    ip += '.';

    foo(l+1, licz+1, ip+S.substr(l+1, 1));

    if(S[l+1] != '0'){
        foo(l+2, licz+1, ip+S.substr(l+1, 2));

        if(num(l+1, 3) <= 255){
            foo(l+3, licz+1, ip+S.substr(l+1, 3));
        }
    }
}

int main(){
    cin >> S;
    n = S.size();

    if(n > 12 || n < 4){
        cout << "NO";
        return 0;
    }

    foo(0, 1, S.substr(0, 1));

    if(S[0] != '0'){
        foo(1, 1, S.substr(0, 2));
        if(num(0, 3) <= 255)
            foo(2, 1, S.substr(0, 3));
    }

    if(ans.empty()) cout << "NO";
    else{
        sort(ans.begin(), ans.end());
        for(string &x : ans)
            cout << x << "\n";
    }
}
