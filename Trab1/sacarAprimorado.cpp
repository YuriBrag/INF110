#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    double valorSaque, qtdCedulas100, qtdCedulas50, qtdCedulas20, qtdCedulas10, qtdCedulas5, qtdCedulas2, 
    qtdMoeda100, qtdMoeda50, qtdMoeda25, qtdMoeda10, qtdMoeda5, qtdMoeda1;

    cin >> valorSaque;
    valorSaque = valorSaque * 100;

    while (valorSaque != 0) {
        if (valorSaque >= 10000) {
            qtdCedulas100 = valorSaque/10000;
            cout << "C " << trunc(qtdCedulas100) << "x 100,00" << endl;
            valorSaque = valorSaque - (trunc(qtdCedulas100) * 10000);
        }

        if (valorSaque >= 5000 && valorSaque < 10000) {
            qtdCedulas50 = valorSaque/5000;
            cout << "C " << trunc(qtdCedulas50) << "x 50,00" << endl;
            valorSaque = valorSaque - (trunc(qtdCedulas50) * 5000);
        }

        if (valorSaque >= 2000 && valorSaque < 5000) {
            qtdCedulas20 = valorSaque/2000;
            cout << "C " << trunc(qtdCedulas20) << "x 20,00" << endl;
            valorSaque = valorSaque - (trunc(qtdCedulas20) * 2000);
        }

        if (valorSaque >= 1000 && valorSaque < 2000) {
            qtdCedulas10 = valorSaque/1000;
            cout << "C " << trunc(qtdCedulas10) << "x 10,00" << endl;
            valorSaque = valorSaque - (trunc(qtdCedulas10) * 1000);
        }

        if (valorSaque >= 500 && valorSaque < 1000) {
            qtdCedulas5 = valorSaque/500;
            cout << "C " << trunc(qtdCedulas5) << "x 5,00" << endl;
            valorSaque = valorSaque - (trunc(qtdCedulas5) * 500);
        }

        if (valorSaque >= 200 && valorSaque < 500) {
            qtdCedulas2 = valorSaque/200;
            cout << "C " << trunc(qtdCedulas2) << "x 2,00" << endl;
            valorSaque = valorSaque - (trunc(qtdCedulas2) * 200);
        }

        if (valorSaque >= 100 && valorSaque < 200) {
            qtdMoeda100 = valorSaque/100;
            cout << "M " << trunc(qtdMoeda100) << "x 1,00" << endl;
            valorSaque = valorSaque - (trunc(qtdMoeda100) * 100);
        }

        if (valorSaque >= 50 && valorSaque < 100) {
            qtdMoeda50 = valorSaque/50;
            cout << "M " << trunc(qtdMoeda50) << "x 0,50" << endl;
            valorSaque = valorSaque - (trunc(qtdMoeda50) * 50);
        }

        if (valorSaque >= 25 && valorSaque < 50) {
            qtdMoeda25 = valorSaque/25;
            cout << "M " << trunc(qtdMoeda25) << "x 0,25" << endl;
            valorSaque = valorSaque - (trunc(qtdMoeda25) * 25);
        }

        if (valorSaque >= 10 && valorSaque < 25) {
            qtdMoeda10 = valorSaque/10;
            cout << "M " << trunc(qtdMoeda10) << "x 0,10" << endl;
            valorSaque = valorSaque - (trunc(qtdMoeda10) * 10);
        }

        if (valorSaque >= 5 && valorSaque < 10) {
            qtdMoeda5 = valorSaque/5;
            cout << "M " << trunc(qtdMoeda5) << "x 0,05" << endl;
            valorSaque = valorSaque - (trunc(qtdMoeda5) * 5);
        }

        if (valorSaque >= 1 && valorSaque < 5) {
            qtdMoeda1 = valorSaque;
            cout << "M " << trunc(qtdMoeda1) << "x 0,01" << endl;
            valorSaque = valorSaque -  trunc(qtdMoeda1);
        }
        
    }
    return 0;
}