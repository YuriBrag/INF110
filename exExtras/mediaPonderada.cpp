#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double n, i, nota1, nota2, nota3, media;
    i = 0;

    do { 
        cin >> n >> nota1 >> nota2 >> nota3;
        cout << fixed << setprecision(1) << (nota1*2 + nota2*3 + nota3*5)/10;
        i++;
    }
    while (n > i);
   
}
