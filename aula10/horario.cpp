#include <iostream>
#include <iomanip>
using namespace std;

struct Horario {
	int horas, minutos;
};

void escreve (Horario h) {
	if (h.horas > 0 && h.horas < 12) {
		cout << fixed << setfill('0') << setw(2) << h.horas << ':' << setfill('0') << setw(2) << h.minutos << " AM" << endl;
	}
	else if (h.horas > 12 && h.horas <= 23) {
		cout <<  fixed << setfill('0') << setw(2) << h.horas - 12 << ':' << setfill('0') << setw(2) << h.minutos << " PM" << endl;
	}
	else if (h.horas == 0) {
		cout <<  fixed << setfill('0') << setw(2) << h.horas + 12 << ':' << setfill('0') << setw(2) << h.minutos << " AM" << endl;
	}
	else if (h.horas == 12) {
		cout <<  fixed << setfill('0') << setw(2) << h.horas << ':' << setfill('0') << setw(2) << h.minutos << " PM" << endl;
	}
};

int main() {
	int n, i, h, min;
	Horario x;
	cin >> n;
	for(i=0; i<n;i++){
		cin >> x.horas >> x.minutos;
		escreve(x);
	}
	return 0;
}
