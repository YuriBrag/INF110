#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n, i;
    long double pi, somatorio;
    cin >> n;
    somatorio = 0;
    for(i = 1; n >= i; i++) {
        somatorio += (long double) 1/pow(i, 2);
    }
    pi = sqrt(somatorio*6);
    cout << fixed << setprecision(62) << pi << endl;
    return 0;
}