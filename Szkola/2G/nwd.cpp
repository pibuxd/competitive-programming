// Hayati Gonultas
// CopyLeft
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

unsigned int bigmodulus(string bignumber, int m) {
    static const int modulus_multiply_e6 = 100000 % m;

    if (bignumber.length() <= 5) {
        int currNumber;
        stringstream(bignumber) >> currNumber;

        return (currNumber % m);
    }

    string rightFiveDigit = bignumber.substr(bignumber.length()-5, 5);

    bignumber = bignumber.substr(0, bignumber.length()-5);

    int remainder;
    stringstream(rightFiveDigit) >> remainder;
    int modulusRemainder = remainder % m;

    return (bigmodulus(bignumber, m)*modulus_multiply_e6 + modulusRemainder) % m;
}

int gcd(int n1, int n2);

int gcd(string bignumber, int othernumber) {
    int m = bigmodulus(bignumber, othernumber);

    if (m == 0)
        return othernumber;

    return gcd(othernumber, m);
}

int gcd(int n1, int n2) {
    if (n1 < n2) {
        int temp = n1;
        n1 = n2;
        n2 = n1;
    }

    if (n1 % n2 == 0)
        return n2;
    else
        n1 = n1 % n2;

    return gcd(n2, n1);
}

int main ()
{
    string bignumber;

    cout << gcd(bignumber, 3) << endl;

    return 0;
}
