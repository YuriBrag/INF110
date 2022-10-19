#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    int i, cont;
    cin >> word;
    cont = 0;
    
    for (i = 0;i < word.length();i++){
        if (word[i] != '.'){
            if(word[i] == word[i+1]){
                cont++;
            }
            if(word[i] != word[i+1]){
            cout << cont + 1 << word[i];
            cont = 0;
            }
        }
    }
    cout << "0" << endl;

    return 0;
}