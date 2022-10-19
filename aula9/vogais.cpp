#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main() {
	char word[50];
	int i;
	double v=0, l=0;
	
	cin >> word;
	
	for(i = 0; word[i] != '\0';i++) {
		if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u') {
			v++;
		}
		else if(word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U') {
			v++;
		}
		l++;
	}
	
	cout << fixed << setprecision(0) <<(v/l)*100 << '%' << endl;
	
	return 0;
}
