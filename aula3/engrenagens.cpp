#include <iostream>
using namespace std;

int main() {
	int engMenor, engMaior;
	cin >> engMenor;
	cin >> engMaior;
	
	if (engMaior % engMenor == 0) {
	cout << "1" << endl;
	}
	 else {
	 cout << "0" << endl;
	}
	return 0;
}
