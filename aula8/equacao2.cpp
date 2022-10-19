#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int eq2grau(double a, double b, double c, double &x1, double &x2){
	double delta;
	delta = (pow(b,2) - (4 * a * c));
	x1 = (-b - sqrt(delta))/(2 * a);
	x2 = (-b + sqrt(delta))/(2 * a);
	
	if(delta == 0) {
		return 1;
	}
	else if(delta < 0) {
		return 0;
	}
	return 2;
}

int main() {
	double x1, x2, a, b, c, raizes;
	
	cin >> a >> b >> c;
	eq2grau(a, b, c, x1, x2);
	raizes = eq2grau(a, b, c, x1, x2);
	
	if(raizes == 1) {
		cout << fixed << setprecision(2) << x1 << endl;
	}
	else if (raizes == 2) {
		cout << fixed << setprecision(2) << x1 << " " << x2 << endl;
	}
	else {
		cout << "Nao ha raiz real"<< endl;
	}
	
	return 0;
}
