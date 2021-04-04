#include <bits/stdc++.h>
using namespace std;

bool porownanie(string A, string B) {
    if(A.size() > B.size())
        return false;
    if(A.size() < B.size())
        return true;
    for(int a = 0; a < A.size(); a++){
        if(A[a] > B[a])
            return false;
        else if(A[a] < B[a])
            return true;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string N[100];
    for (int a = 0; a < n; a++)
        cin >> N[a];
    sort(N, N + n, porownanie);
    for (int a = 0; a < n; a++)
        cout << N[a] << endl;

}
