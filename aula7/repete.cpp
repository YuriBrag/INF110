#include <iostream>
using namespace std;

int main() {
    int j = 0, k, i, nLines, nTerms;
    bool repeat = false;

    cin >> nLines;

    int v[nLines][10000];

    while (j < nLines) {
        cin >> nTerms;
        int termRepeated;
        for (i = 0; i < nTerms; i++) {
            cin >> v[j][i];
        }
        for (i = 0; i < nTerms; i++) {
            for(k=nTerms-1;k>=0;k--){
                if(k==i) {
                    continue;
                }
                if (v[j][i] == v[j][k]) {
                    termRepeated = v[j][i]; 
                    repeat = true;
                }
            }
        }
        if(repeat) {
            cout << "SIM: " << termRepeated << endl;
            repeat = false;
        }
        else {
            cout << "NAO" << endl;
        }
        j++;

    }
    return 0;
}
