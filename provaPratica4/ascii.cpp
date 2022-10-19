#include <iostream>
using namespace std;

int main() {
	int n, m, i, j, l, c, posInx, posIny, cont1=0, cont2=0; 
	cin >> n >> m;
	char p[n][m];
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			cin >> p[i][j];
		}
	}
	cin >> l >> c >> posInx >> posIny;
	
	for(i = posInx-1; cont1 < l; i++, cont1++) {
		for(j = posIny-1; cont2 < c; j++, cont2++) {
			cout << p[i][j];
		}
		cout << endl;
		j = posIny-1;
		cont2 = 0;
	}
	
	return 0;
}
