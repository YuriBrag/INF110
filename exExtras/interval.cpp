#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    long long int n, i, num, contIn, contOut;
    cin >> n;
    i = 0;
    contIn = 0;
    contOut = 0;
    
    do {
        cin >> num;
        if (num >= 10 && num <= 20  ){
            contIn++;
        }
        else {
            contOut++;
        }
        i++;
    }
    while (n > i);

    cout << contIn << " in" << endl;
    cout << contOut << " out" << endl;
    return 0;
    
}