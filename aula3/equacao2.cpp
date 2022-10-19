#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double delta, a, b, c, x1, x2;
	
	cin >> a >> b >> c;
	
	delta = (b * b) - (4 * a * c);
	
	if (delta < 0) {
	cout << "Nao ha raiz real" << endl;
	}
	else if (delta > 0) {
	x1 = ((-1 * b) + sqrt(delta))/(2 * a);
	x2 = ((-1 * b) - sqrt(delta))/(2 * a);
	cout << fixed << setprecision(2) << x2 << " " << x1 << endl;
	}
	else if (delta == 0) {
	x1 = (sqrt(delta) - b)/(2 * a);
	cout << fixed << setprecision(2) << x1 << endl;
	}
	return 0;
}
