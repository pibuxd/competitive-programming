#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int *tab = new int[n];
    int m = 0;
    int pod = 0;
    int z;
    for (int a = 0; a < n; a++) tab[a] = 0;
    for (int a = 0; a < q; a++) {
        //cout<<a;
        cin >> z;
        z--;
        if (z == n)
            pod = m;
        else {
            if (tab[z] < pod)
                tab[z] = pod + 1;
            else tab[z]++;
            if (tab[z] > m) m++;
        }
        //cout<<tab[z]<<endl;
    }
    for (int a = 0; a < n; a++) {
        if (pod > tab[a]) cout << pod << " ";
        else cout << tab[a] << " ";
    }

}
