#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int nstudents, ntests;
    cin >> nstudents >> ntests;
    int score[nstudents][ntests];
    int i, j, sum=0;

    for (i = 0; i < nstudents; i++) {
        for (j = 0; j < ntests; j++) {
            cin >> score[i][j];
        }
    }

    for (i = 0; i < nstudents; i++) {
        for (j = 0; j < ntests; j++) {
            sum += score[i][j];
        }
        cout << sum << endl;
        sum = 0;
    }
    
    return 0;
}