#include <iostream>
using namespace std;

int main() {
    int lines, columns, i,j;
    cin >> lines >> columns;
    int chart[lines][columns];
    for(i = 0;i < lines;i++) {
        for(j = 0;j < columns;j++) {
            cin >> chart[i][j];
        }
    }
    for(i = 0;i < columns;i++) {
        for(j = 0;j < lines-1;j++) {
            cout << chart[j][i] << " ";
        }
        cout << chart[j][i];
        cout << endl;
    }


    return 0;
}