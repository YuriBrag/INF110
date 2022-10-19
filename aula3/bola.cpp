#include <iostream>
using namespace std;

int main() {
	int diam, alt, larg, prof, vol, resultado;
	
	cin >> diam;
	cin >> alt >> larg >> prof;
	
	if ( diam <= alt && diam <= larg && diam <= prof) {
	cout << "S" << endl;
	}
	else {
	cout << "N" << endl;
	}
	return 0;
}
