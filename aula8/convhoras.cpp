#include <iostream>
#include <iomanip>
using namespace std;

void convhoras(int seg, int &h, int &m, int &s) {
	 
	 h = seg/3600;
	 m = (seg - h*3600)/60;
	 s = seg - (h*3600) - (m*60);

}


int main() {
	int h, m, s, seg;
	cin >> seg;
	
	convhoras(seg, h, m, s);
	
	cout << setw(2) << setfill('0') << h << ":" << setw(2) <<  setfill('0') << m << ":" << setw(2) << setfill('0') << s << endl;
	return 0; 
}
