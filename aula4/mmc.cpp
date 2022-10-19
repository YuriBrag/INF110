#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int a, b, cont;
	
	cin >> a >> b;
	
	if(a >= b){
	cont = a;
	}
	
	if(b >= a){
	cont = b;
	}
		
	while (cont % a !=0 ||	 cont % b !=0) {
		cont++;
	}
	cout << cont << endl;
	return 0;
}
