#include <iostream>
using namespace std;

int main() {
    int n, i;
    cin >> n;
    int numbers[n];

    for (i = 0; i < n;i++) {
        cin >> numbers[i];
    }
    for (i = n-1; i > 0; i--) {
        cout << numbers[i] << " ";
    }
    cout << numbers[0] << endl;

    return 0;
}