#include <iostream>
using namespace std;

int main() {
    int eggs, i;

    cin >> eggs;

    if (eggs == 1) {
        cout << "1 x 1" << endl;
    }

    for (i = 1; i < eggs; i++) {
        if(eggs%i == 0) {
            cout << i << " x " << eggs/i << endl;
        }
        if(i+1 > eggs/(i+1)){
            break;
        }
    }
    return 0;
} 