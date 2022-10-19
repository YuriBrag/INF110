#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double A, B, C, delta;
	
	cin >> A >> B >> C;
	delta = (B*B)-(4*(A*C));
	cout << fixed << setprecision(4) << ((-1*(B))+sqrt(delta))/(2*A) << " ";
	cout << fixed << setprecision(4) << ((-1*(B))-sqrt(delta))/(2*A) << endl;
	return 0;
}
