#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	long long int popInfec, txTransm, semanas;
	
	cin >> popInfec >> txTransm;
	semanas = 0;
	
	while (popInfec < 1000000000) {
		popInfec = popInfec + (popInfec * txTransm);
		semanas++;
	}
	cout << semanas << endl;
	return 0;
}
