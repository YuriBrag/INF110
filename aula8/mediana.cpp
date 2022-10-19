#include <iostream>
#include <iomanip>
using namespace std;

void Bolha (int a[], int n) {
	int i, aux;
	for(i=0; i<n-1; i++) {
		if(a[i] > a[i+1]) {
			a[i] = aux;
			a[i] = a[i+1];
			a[i+1] = aux;
		}
	}
}


int main() {
	int n, i, total = 0, pos, mediana;
	cin >> n;
	int v[n];
	for(i=0; i<n;i++) {
		cin >> v[i];
	}
	Bolha(v, n);
	
	for (i=0; i<n; i++) {
		total += v[i];
	}
	cout << fixed << setprecision(1) << "Media" << (double)total/2 << endl;
	if(n%2 == 0) {
		pos = n/2;
		mediana = (v[pos] + v[pos-1])/2;
	}
	if(n%2 != 0) {
		pos = n/2;
		mediana = v[pos+1];
	}
	return 0;
}
