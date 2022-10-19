#include <iostream>
using namespace std;

int main() {
    double volume, altura, largura, comprimento;

    cout << "Escreva o valor da altura, largura e comprimento da caixa em metros" << endl;
    cin >> altura >> largura >> comprimento;
    volume = altura * largura * comprimento;
    cout << "O volume é: " << volume << "metros cúbicos";

    return 0;
}