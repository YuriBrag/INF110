#include <iostream>
using namespace std;

int main() {
    int n, i , j, sum;
    cin >> n;
    int a[n];
    bool cond=false;

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> sum;

    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (sum == a[i]+a[j]){
                cond = true;
            }
        }
    }
    if (cond == true) {
        cout << "SIM" << endl;
    }
    else {
        cout << "NAO" << endl;
    }

    return 0;
}