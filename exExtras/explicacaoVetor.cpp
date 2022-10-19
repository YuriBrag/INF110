#include <iostream>
using namespace std;

int main() {
    int n, i;
    cin >> n;
    int vector[n]; //vai criar um vetor de tamanho n, se vc der cin em 3 vai criar uma lista chamada vetor que vai ter as posicoes 0, 1 e 2

    for (i = 0;i < n; i++) { //cria um contador para que vc possa preencher o vetor de alguma forma, ele vai comecar na posicao 0, vai
        cin >> vector[i];   // colocar o numero que voce der cin na posicao vetor[0] vai acrescentar 1 no i, ou seja agora i vale 1
    }                       // vai verificar se i < n, se for vai entrar no for de novo pra dar cin na posicao vetor[1], dessa forma preenchendo o vetor
    for (i = 0;i < n; i++) {
        cout << vector[i] << " "; // cria de novo um contador q da cout em vector[0], dps acrescenta um em i, da cout em vetor[1]
    }                             // verifica se i < n, se for da cout em vetor[1], assim por diante
    return 0;
}