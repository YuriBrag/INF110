#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    double valorSaque;

    cin >> valorSaque;
    
    //transformei para centavos para facilitar as contas, e tratar todas as possibilidades como inteiras
    //e arredondei caso tenha mais casas decimais além dos 1 centavo
    valorSaque = round(valorSaque * 100);
    //Enquanto não zerar o valor do saque não irá interromper o while.
    
    //A cada if verdadeiro irá imprimir o valor de uma cédula ou moeda e retirar o valor dela do montante
    //e assim passar adiante até zerar o valorSaque.
    while (valorSaque != 0 && valorSaque > 0.99 && valorSaque > 0) {
        if (valorSaque >= 10000) {
            cout << "C 100" << endl;
            valorSaque = valorSaque - 10000;
        }

        if (valorSaque >= 5000 && valorSaque < 10000) {
            cout << "C 50" << endl;
            valorSaque = valorSaque - 5000;
        }

        if (valorSaque >= 2000 && valorSaque < 5000) {
            cout << "C 20" << endl;
            valorSaque = valorSaque - 2000;
        }

        if (valorSaque >= 1000 && valorSaque < 2000) {
            cout << "C 10" << endl;
            valorSaque = valorSaque - 1000;
        }

        if (valorSaque >= 500 && valorSaque < 1000) {
            cout << "C 5" << endl;
            valorSaque = valorSaque - 500;
        }

        if (valorSaque >= 200 && valorSaque < 500) {
            cout << "C 2" << endl;
            valorSaque = valorSaque - 200;
        }

        if (valorSaque >= 100 && valorSaque < 200) {
            cout << "M 100" << endl;
            valorSaque = valorSaque - 100;
        }

        if (valorSaque >= 50 && valorSaque < 100) {
            cout << "M 50" << endl;
            valorSaque = valorSaque - 50;
        }

        if (valorSaque >= 25 && valorSaque < 50) {
            cout << "M 25" << endl;
            valorSaque = valorSaque - 25;
        }

        if (valorSaque >= 10 && valorSaque < 25) {
            cout << "M 10"<< endl;
            valorSaque = valorSaque - 10;
        }

        if (valorSaque >= 5 && valorSaque < 10) {
            cout << "M 5" << endl;
            valorSaque = valorSaque - 5;
        }

        if (valorSaque >= 1 && valorSaque < 5) {
            cout << "M 1" << endl;
            valorSaque = valorSaque - 1;
        }
    }
    return 0;
}