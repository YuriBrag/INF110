#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double temp, emCel, emFah;
	char escala;
	
	cin >> temp >> escala;
	
	
	if (escala == 'F') {
	emCel = (temp - 32) * 5/9 ;
	cout << fixed << setprecision(1) << emCel << " C" << endl;
	}
	else if (escala == 'C') {
	emFah = (temp * 1.8) + 32;
	cout << fixed << setprecision(1) << emFah << " F" << endl;
	}
	return 0;
}

