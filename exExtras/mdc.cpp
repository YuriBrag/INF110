#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int mdc, a, b, maior, menor;
    cin >> a >> b;
    if (a > b) {
        maior = a;
        menor = b;
    }
    if (a < b) {
        maior = b;
        menor = a;
    }
    mdc = maior;
    while (a%mdc !=0 || b%mdc != 0) {
        mdc--;
    }
    cout << mdc << endl;
    return 0;
}