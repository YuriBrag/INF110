#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double raio, altura;
	
	cin >> raio;
	cin >> altura;
	cout << fixed << setprecision(2) << (3.1415*(raio)*(raio))*(altura) << endl;
	return 0;
}
