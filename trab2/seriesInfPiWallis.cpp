#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int i, n, j;
    long double pi, produto;
    cin >> n;
    produto = 1;
    if (n%2 ==0) {
        for (i = 2; n >= i; i += 2) {
            produto *= (long double)(i * i)/((i-1) * (i+1));
        }
    }
    else {
        j = n-1;
        for (i = 2; j >= i; i += 2) {
            produto *= (long double)(i * i)/((i-1) * (i+1));
        }
        produto = produto * i/(i-1);

    }
    pi = 2*produto;
    cout << fixed << setprecision(62) << pi << endl;
    return 0;
}