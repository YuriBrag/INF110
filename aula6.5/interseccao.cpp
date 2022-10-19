#include <iostream>
using namespace std;

int main() {
    int n1, n2, cont, i , j;
    cin >> n1 >> n2;
    int a[n1], b[n2];

    for (i = 0; i < n1; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n2; i++) {
        cin >> b[i];
    }

    cout << '{';
    for (i = 0; i < n1; i++){
        for(j = 0; j < n2; j++) {
            if (a[i] == b[j]) {
                cout << a[i] << " ";
            }
        }
    }
    cout << '}' << endl;

    return 0;
}