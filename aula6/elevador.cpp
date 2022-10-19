#include <iostream>
using namespace std;

int main() {
    int n, c, i, enters, exits, sum=0;
    bool maxCap = false;
    cin >> n >> c;
    for (i = 0; i < n; i++) {
        cin >> exits >> enters;
        sum += enters - exits;
        if (sum > c) {
            maxCap = true;
        }
    }
    if (maxCap ==  true) {
        cout << "S" << endl;
    }
    else {
        cout << "N" << endl;
    }
    return 0;
}