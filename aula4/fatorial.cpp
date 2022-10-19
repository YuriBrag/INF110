#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	long int n, fatorial;
	
	cin >> n;
	fatorial = 1;
	
	while (n > 0) {
		fatorial = fatorial * n;
		n = n - 1;
	}
	
	cout << fatorial << endl;
	return 0;
}
