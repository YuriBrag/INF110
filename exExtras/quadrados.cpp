#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    long long int n, i;
    cin >> n;
    i = 2;
    while (n >= i) {
        cout << i <<  "^2 = " << pow(i,2) << endl;
        i+=2;
    }
    return 0;
}