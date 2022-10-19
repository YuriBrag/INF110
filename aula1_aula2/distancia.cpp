#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double x1, x2, y1, y2, distancia;
	
	cin >> x1 >> y1 >> x2 >> y2;
	distancia = ((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2));
	cout << fixed << setprecision(2) << sqrt(distancia) << endl;
	return 0;
}
