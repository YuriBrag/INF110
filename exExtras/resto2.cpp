#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n, i;
    cin >> n;
    i = 0;
    while (i < 10000) {
        if (i%n == 2) {
            cout << i << endl;
            i++;
        }
        else {
            i++;
        }
    }
    return 0;
}