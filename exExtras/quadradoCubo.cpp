#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n, i;
    cin >> n;

    for (i=1; n >= i; i++) {
        cout << i << " " << i*i << " " << i*i*i << endl;
    }
    return 0;
}