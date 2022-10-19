#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char p[50];
	bool num=false, esp=false, maiuscula=false, minuscula=false;
	int seg = 0, i, cont = 0;
	
	cin >> p;
	
	for(i=0; p[i]!='\0';i++) {
		if(p[i] >= 48 && p[i] <= 57) {
			num = true;
		}
		if(p[i] >= 65 && p[i] <= 90) {
			maiuscula = true;
		}
		if(p[i] >= 97 && p[i] <= 122) {
			minuscula = true;
		}
		else {
			esp = true;
		}
	}
	
	if(num) {
		seg+=1;
	}
	if(maiuscula) {
		seg+=1;
	}
	if(minuscula) {
		seg+=1;
	}
	if(esp) {
		seg+=1;
	}
	
	if(seg == 4) {
		cout << "segura" << endl;
	}
	if (seg == 3 || seg == 2) {
		cout << "media" << endl;
	}
	if (seg == 1) {
		cout << "fraca" << endl;
	}
	
	return 0;
}
