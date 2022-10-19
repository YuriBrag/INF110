#include <iostream>
using namespace std;

int main() {
    int lines, columns, i, j, value, count = 0;;
    cin >> lines >> columns;
    int matriz[lines][columns];

    for(i = 0; i < lines; i++) {
        for(j = 0;j < columns;j++) {
            cin >> matriz[i][j];
        }
    }
    cin >> value;
    for(i = 0; i < lines; i++) {
        for(j = 0;j < columns;j++) {
            if(matriz[i][j] == value) {
                count++;
            }
        }
        cout << count << endl;
        count = 0;
    }

    return 0;
}