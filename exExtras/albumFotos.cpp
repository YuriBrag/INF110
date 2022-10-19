#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int album[2], foto1[2], foto2[2], altAlbum, altFt1, altFt2, largAlbum, largFt1, largFt2;
    long long int cont, largFt, altFt, tam1, tam2, i;

    for(i = 0; i <= 1; i++) {
        cin >> album[i];
    }
    for(i = 0; i <= 1; i++) {
        cin >> foto1[i];
    }
    for(i = 0; i <= 1; i++) {
        cin >> foto2[i];
    }
    sort(album, album+2);
    sort(foto1, foto1+2);
    sort(foto2, foto2+2);

    altAlbum = album[1];
    largAlbum = album[0];
    altFt1 = foto1[1];
    largFt1 = foto1[0];
    altFt2 = foto2[1];
    largFt2 = foto2[0];

    largFt = largFt1 + largFt2;
    altFt = altFt1 + altFt2;
    tam1 = altFt1 + largFt2;
    tam2 = largFt1 + altFt2;

    cont = 0;

    if (largFt1 <= largAlbum && largFt2 <= largAlbum && altFt <= altAlbum) {
        cont++;
    }
    if (altFt1 <= largAlbum && altFt2 <= largAlbum && largFt <= altAlbum) {
        cont++;
    }
    if (altFt1 <= largAlbum && largFt2 <= largAlbum && tam2 <= altAlbum) {
        cont++;
    }
    if (tam1 <= altAlbum && largFt1 <= largAlbum && altFt2 <= largAlbum) {
        cont++;
    }
    if (largFt <= largAlbum && altFt1 <= altAlbum && altFt2 <= altAlbum) {
        cont++;
    }
    if (largFt <= altAlbum && altFt1 <= largAlbum && altFt2 <= largAlbum) {
        cont++;
    }
    

    if (cont != 0) {
        cout << "S" << endl;
    }
    if (cont == 0) {
        cout << "N" << endl;
    }
    
    return 0;
}