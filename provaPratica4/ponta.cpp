#include <iostream>
using namespace std;

int main() {
	int n, i, j, cont=0, somaZeros;
	bool flecha = true;
	cin >> n;
	int m[n][n];
	somaZeros = (n-1) * (n-2);
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}
	for(i=0, j = 0; i < n; i++) {
		if (m[i][j] == 0) {
			flecha = false;
		}
	}
	for(j=0, j = 0; i < n; j++) {
		if (m[i][j] == 0) {
			flecha = false;
		}
	}
	for(i = 0, j = 0; i < n; i++ ,j++) {
		if (m[i][j] == 0) {
			flecha = false;
		}
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(m[i][j] == 0) {
				cont++;
			}
		}
	}
	if(flecha && cont == somaZeros) {
		cout << "SIM" << endl;
	}
	else {
		cout << "NAO" << endl;
	}

	return 0;
}
