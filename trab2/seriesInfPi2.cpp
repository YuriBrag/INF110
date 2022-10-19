#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n, j, i;
    long double soma, sub, pi;
    cin >> n;
    if (n%2==0) {
        soma=0;
        sub=0;
        long double nPosi[n/2], nNeg[n/2];
        j = n/2;
        for (i = 0; j > i ; i++) {
            nPosi[i] = 1.00/(((long double)i*2.00)+3.00);
            nNeg[i] = 1.00/(((long double)i*4.00)+3.00);
        }
        nPosi[0] = 1.00;
        nNeg[0] = 1.00/3.00;
        for (i=0; j > i; i++) {
            soma += nPosi[i];
            sub += nNeg[i];
        }
    }
    pi = 4.00*(soma-sub);
    cout << fixed << setprecision(62) << pi << endl;

    return 0;
}