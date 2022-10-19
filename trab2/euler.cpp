#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    long double ntermos, euler, fatorial;

    cin >> ntermos;
    fatorial = 1.0;
    euler = 1.0;


    for(int i = 1.0; i<=ntermos; i++){
        fatorial = i*fatorial;
        euler += 1.0/(fatorial);}

    cout << fixed << setprecision(62) << euler << endl;

return 0;}