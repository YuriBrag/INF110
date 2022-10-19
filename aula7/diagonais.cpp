#include <iostream>
using namespace std;

int main(){
    int n, i, j;
    cin >> n;
    int matriz[n][n];

    for(i = 0;i < n; i++) {
        for(j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }
    for(i = 0;i < n;i++) {
        cout << matriz[i][i] << endl;
    }
    cout << endl;
    for(i = n-1, j = 0;i >= 0;i--, j++) {
        cout << matriz[j][i] << endl;
    }
    
    return 0;
}