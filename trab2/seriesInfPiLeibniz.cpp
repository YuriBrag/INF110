#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    long double pi, soma;
    int n, i, cont;
    cin >> n;
    soma = 0;
    cont = 0;
    if(n%2 == 0) {
        for (i = 1; n > cont;i += 4){
            soma += (1/(long double)i) - (1/((long double)i+2));
            cont += 2;
        }
    }
    else {
        for (i = 1; n-1 > cont;i += 4){
            soma += (1/(long double)i) - (1/((long double)i+2));
            cont += 2;
        }
        soma += (1/(long double)i);
    }
    pi = 4.00*soma;
    cout << fixed << setprecision(62) << pi << endl;
    return 0;

}
