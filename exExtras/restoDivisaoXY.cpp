#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    long long int x, y, maior, menor, i;
    cin >> x >> y;
    
    if (x > y) {
        maior = x;
        menor = y;
    }
    if (y > x) {
        maior = y;
        menor = x;
    }

    for (i = menor + 1; maior > i; i++) {
        if (i%5 == 2 || i%5 == 3) {
            cout << i << endl;
        }
    } 
}