#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Ponto {
	int x,y;
};

double distancia (Ponto A, Ponto B) {
	double dist;
	dist = sqrt(pow(B.x - A.x,2) + pow(B.y - A.y,2));
		
	return dist;
};

double area (Ponto P, Ponto Q, Ponto R) {
	double distAB, distAC, distBC, semiP;
	
	distAB = distancia(P, Q);
	distAC = distancia(P, R);
	distBC = distancia(Q, R);
	semiP = (distAB + distAC + distBC)/2;
	
	return sqrt(semiP *(semiP - distAB) * (semiP - distAC) * (semiP - distBC)); 
};

int main() {
	Ponto pA, pB, pC;
	double a;
	
	cin >> pA.x >> pA.y >> pB.x >> pB.y >> pC.x >> pC.y;
	
	a = area(pA, pB, pC);
	
	cout << fixed << setprecision(2) << a << endl;
	
	return 0;
}
