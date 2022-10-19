#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    long double pi, soma, sub;
    int n, i, nNeg, nPosi, cont;
    cin >> n;
    soma = 0;
    sub = 0;
    if (n%2==0) {
        nPosi = n/2;
        nNeg = n/2;
        for (i=0; nPosi > i; i++) {
            soma += 1.00/((long double)i*2+3); 
        }
        for (i=0; nNeg > i; i++) {
            sub += 1.00/((long double)i*4+3);
        }

    }
    else {
        nPosi = (round)(n/2);
        nNeg = round(n/2)-1;
        for (i=0; nPosi > i; i++) {
            soma += 1.00/((long double)i*2+3);
        }
        for (i=0; nNeg > i; i++) {
            sub += 1.00/((long double)i*4+3);
        }
    }
    
    pi = 4.00*(soma - sub);
    cout << fixed << setprecision(62) << pi << endl;
    return 0;
}