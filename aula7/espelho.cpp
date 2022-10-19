#include <iostream>
using namespace std;

int espelhar(int n) {
    int inverted, r1, r2, r3, r4;

    r4 = n/1000;
    r3 = (n - (r4 * 1000))/100;
    r2 = (n - (r3 * 100) - (r4 * 1000))/10;
    r1 = n- (r2 * 10)-(r3 * 100)-(r4 * 1000);
    
    inverted = (r1 * 1000) + (r2 * 100) + (r3 * 10) + r4; 

    return inverted;
}

int main() {
    int n1 = 1, n2 = 1, inverted;
    while(n1 !=0 && n2 !=0) {
        cin >> n1 >> n2;
        if(n1 == 0 && n2 == 0) {
            break;
        }
        inverted = espelhar(n1);

        if (inverted == n2) {
            cout << "espelho" << endl;
        }
        else {
            cout << "nao espelho" << endl;
        }
    }

    return 0;
}