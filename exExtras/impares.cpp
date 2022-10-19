#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n, i;
    i = 1;
    cin >> n;
    while (n >= i) {
        cout << i << endl;
        i += 2;
    }
    return 0;
}