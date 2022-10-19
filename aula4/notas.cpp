#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	
	int contador;
	double nota, total, nAlunos;
		
	cin >> nAlunos;
		
	contador = 0;
		
	while (nAlunos > contador) {
		cin >> nota;
		total = total + nota;
		contador = contador + 1;	
	}
	
	cout << fixed << setprecision(2) << total/nAlunos << endl;
	return 0;
}
