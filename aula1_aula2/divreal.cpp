#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double A,B;
	
	cin >> A;
	cin >> B;
	cout<< fixed << setprecision(2) << A/B << endl;
	return 0; 
}
