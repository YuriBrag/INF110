#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double notaFinal, dist, notaDist, notaMaior, notaMenor, notaEstilo, juiz1, juiz2, juiz3, juiz4, juiz5;

    cin >> dist >> juiz1 >> juiz2 >> juiz3 >> juiz4 >> juiz5;

    notaDist = ((dist - 120)* 1.8) + 60; //calcula a nota da distância
    
    //verifica qual é a variável maior(j1,j2,j3,j4,j5), nesse caso não precisa ser feito igual à condicional
    //passada em aula (diminuindo os ifs), pois caso duas ou mais variáveis sejam iguais vai apenas 
    //sobrescrver a outra (só funciona com if, não com else if)

    if (juiz1 >= juiz2 && juiz1 >= juiz3 && juiz1 >= juiz4 && juiz1 >= juiz5) {
        notaMaior = juiz1;
    }
    if (juiz5 >= juiz4 && juiz5 >= juiz3 && juiz5 >= juiz2 && juiz5 >= juiz1)  {
       notaMaior = juiz5;
    }
    if (juiz2 >= juiz4 && juiz2 >= juiz3 && juiz2 >= juiz5 && juiz2 >= juiz1)  {
        notaMaior = juiz2;
    }
    if (juiz4 >= juiz1 && juiz4 >= juiz2 && juiz4 >= juiz5 && juiz4 >= juiz3)  {
        notaMaior = juiz4;
    }
    if (juiz3 >= juiz4 && juiz3 >= juiz1 && juiz3 >= juiz2 && juiz3 >= juiz5) {
        notaMaior = juiz3;
    }

    //verifica qual é a variável menor(j1,j2,j3,j4,j5)
    if (juiz1 <= juiz4 && juiz1 <= juiz3 && juiz1 <= juiz2 && juiz1 <= juiz5) {
        notaMenor = juiz1;
    }
    if (juiz5 <= juiz4 && juiz5 <= juiz3 && juiz5 <= juiz2 && juiz5 <= juiz1)  {
        notaMenor = juiz5;
    }
    if (juiz2 <= juiz4 && juiz2 <= juiz3 && juiz2 <= juiz5 && juiz2 <= juiz1)  {
        notaMenor = juiz2;
    }
    if (juiz3 <= juiz4 && juiz3 <= juiz1 && juiz3 <= juiz2 && juiz3 <= juiz5)  {
        notaMenor = juiz3;
    }
    if(juiz4 <= juiz1 && juiz4 <= juiz2 && juiz4 <= juiz5 && juiz4 <= juiz3) {
        notaMenor = juiz4;
    }

    //imprime a nota final
    notaEstilo = (juiz1 + juiz2 + juiz3 + juiz4 + juiz5) - (notaMaior + notaMenor);
    notaFinal = notaEstilo+ notaDist;
    cout << fixed << setprecision(1) << notaFinal << endl;
    return 0;

}