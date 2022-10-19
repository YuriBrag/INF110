#include <iostream>
using namespace std;

struct Aluno {
	int mat, nota;
};
void ordena(Aluno v[], int n) {
	int i, j;
	Aluno aux;

	for(i=0; i<n-1;i++) {
		for(j=0; j<n-1;j++) {
			if(v[j].mat > v[j+1].mat) {
				aux.mat = v[j].mat;
				aux.nota = v[j].nota;
				v[j].mat = v[j+1].mat;
				v[j].nota = v[j+1].nota;
				v[j+1].mat = aux.mat;
				v[j+1].nota = aux.nota;
			}	
		}
	}
};

int main() {
	int n, i;
	
	cin >> n;
	
	Aluno a[n];
	
	for(i=0;i<n;i++) {
		cin >> a[i].mat >> a[i].nota;
	}
	
	ordena(a,n);
	for(i=0;i<n;i++) {
		cout << a[i].mat << " " << a[i].nota << endl;
	}

	return 0;
}
