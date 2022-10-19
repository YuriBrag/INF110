#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){

    long double ntermos, sen, cos, fatorial, angulo, rad;
    long double pi = 3.141592653589;
    int cont;

    cin >> ntermos >> angulo;

    //calulando o angulo em rad
    rad = pi/(180/angulo);
    
    //seno
    sen = rad; 
    fatorial = 1;
    cont = 0;
    for(int i = 1; i <= ntermos;i++ ) {
        fatorial = fatorial * i;
       if(i%2 == 1) {
        sen -= (pow(rad,i)/fatorial) + (pow(rad, (i+2)))/((fatorial*(i+1))*i+2);}
    } 

    cout << sen << endl;
    return 0;
}