#include <iostream>
using namespace std;

bool divresto(int a, int b, int &quo, int &rest) {
	
	quo = a/b;
	rest = a%b;

	return true;
}


int main() {
	int n, x, y, quo, rest, i;
	cin >> n;
	for (i = 0; i<n;i++) {
		cin >> x >> y;
		if (y!=0) {
			divresto(x, y, quo, rest);
			cout << quo << " " << rest << endl;
		}
		
		if(y == 0){
			cout << "indefinido" << endl;
		}
	}
	
	return 0;
}
