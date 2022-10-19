#include <iostream>
using namespace std;

int main() {
	char p[50];
	int i, j, l=0;
	bool palin = true;
	
	cin >> p;
	
	for(i=0; p[i] != '\0'; i++) {
		l++;
	}
	for(i=0,j=l-1;p[i] != '\0'; i++, j--) {
		if(p[i] != p[j]) {
			palin = false;
		}
	}
	if(palin) {
		cout << "PALINDROMO" << endl;
	}
	else {
		cout << "NAO" << endl;
	}
	return 0;
}
