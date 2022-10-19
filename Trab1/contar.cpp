#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    double acrescimo, total;
    // enquanto o input não for 0 ele vai continuar acrescentando a variável acréscimo ao montante total
    while (acrescimo != 0) {
        cin >> acrescimo;
        total = total + acrescimo;
    }
    //como o valor está em centavos o total divide por 100
    cout << fixed << setprecision(2) <<"R$"<< total/100 << endl;
    return 0;
}