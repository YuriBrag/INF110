#include <iostream>
using namespace std;

int main() {
	char p[200], sigla[200] = {'\n'};
	int i, j=0;
	cin.getline(p,200);
	for(i=0; p[i]!='\0'; i++) {
		if(p[i] >= 65 && p[i] <= 90) {
			sigla[j] = p[i];
			j++;
		}
	}
	for(j=0; sigla[j]!='\0'; j++) {
		cout << sigla[j];
	}
	cout << endl;
	
	return 0;
}
