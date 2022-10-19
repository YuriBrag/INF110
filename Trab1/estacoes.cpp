#include <iostream>
using namespace std;

int main() {
    int dia, mes;

    cin >> dia >> mes;

    if (mes == 1){
        cout << dia << " de "<< "janeiro" << endl;
        cout << "Verao" << endl;
    }
    else if (mes == 2) {
        cout << dia << " de "<< "fevereiro" << endl;
        cout << "Verao" << endl;
    }
    else if (mes == 3 && dia < 20) {
        cout << dia << " de "<< "marco" << endl;
        cout << "Verao" << endl;
    }
    else if (mes == 3 && dia >= 20) {
        cout << dia << " de "<< "marco" << endl;
        cout << "Outono" << endl;
    }
    else if (mes == 4) {
        cout << dia << " de "<< "abril" << endl;
        cout << "Outono" << endl;
    }
    else if (mes == 5) {
        cout << dia << " de "<< "maio" << endl;
        cout << "Outono" << endl;
    }
    else if (mes == 6 && dia < 21) {
        cout << dia << " de "<< "junho" << endl;
        cout << "Outono" << endl;
    }
    else if (mes == 6 && dia >= 21) {
        cout << dia << " de "<< "junho" << endl;
        cout << "Inverno" << endl;
    }
    else if (mes == 7) {
        cout << dia << " de "<< "julho" << endl;
        cout << "Inverno" << endl;
    }
    else if (mes == 8) {
        cout << dia << " de "<< "agosto" << endl;
        cout << "Inverno" << endl;
    }
    else if (mes == 9 && dia < 22) {
        cout << dia << " de "<< "setembro" << endl;
        cout << "Inverno" << endl;
    }
    else if (mes == 9 && dia >= 22) {
        cout << dia << " de "<< "setembro" << endl;
        cout << "Primavera" << endl;
    }
    else if (mes == 10) {
        cout << dia << " de "<< "outubro" << endl;
        cout << "Primavera" << endl;
    }
    else if (mes == 11) {
        cout << dia << " de "<< "novembro" << endl;
        cout << "Primavera" << endl;
    }
    else if (mes == 12 && dia < 21) {
        cout << dia << " de "<< "dezembro" << endl;
        cout << "Primavera" << endl;
    }
    else if (mes == 12 && dia >=21) {
        cout << dia << " de "<< "dezembro" << endl;
        cout << "Verao" << endl;
    }
    else {
        cout << "Data invalida" << endl;
    }


    return 0;
}