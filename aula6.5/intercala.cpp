#include <iostream>
using namespace std;

int main() {
    long long int n, i;
    cin >> n;
    long long int firstList[n], secondList[n];
    for (i = 0; i < n;i++) {
        cin >> firstList[i];
    }
    for (i = 0;i < n;i++) {
        cin >> secondList[i];
    }
    for (i = 0;i < n;i++) {
        cout << firstList[i] << " ";
        cout << secondList[i] << " ";
    }
    cout << endl;      

    return 0;
}