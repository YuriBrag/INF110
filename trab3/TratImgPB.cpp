// INF110 - Trabalho pratico 3
//
// programa para ler, modificar e gravar uma imagem no formato PNM
//
// Autores: Andre Gustavo dos Santos			(criado em 16/06/14)
//          Andre Gustavo dos Santos			(modificado em 22/05/18)
//		    Andre Gustavo dos Santos			(modificado em 13/09/21)
//			Andre Gustavo dos Santos			(modificado em 25/06/22)

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>

const int MAXALTURA  = 500;				//tamanho maximo aceito (pode ser alterado)
const int MAXLARGURA = 500;

using namespace std;

int main() {
	unsigned char imagem[MAXALTURA][MAXLARGURA];	//a imagem propriamente dita
	int largura, altura;							//dimensoes da imagem
	char tipo[4];									//tipo da imagem
	ifstream arqentrada;							//arquivo que contem a imagem original
	ofstream arqsaida;								//arquivo que contera a imagem modificada
	char comentario[200], c;						//auxiliares
	int i, j, valor;								//auxiliares
	string nomearq;								//nome do arquivo

//*** LEITURA DA IMAGEM ***//
//inicialmente nao sera necessario entender nem mudar nada nesta parte

	//*** Abertura do arquivo ***//
	cout << "Nome do arquivo com a imagem PNM: ";
	cin >> nomearq;
	arqentrada.open(nomearq + ".pnm",ios::in); //Abre arquivo para leitura
	if (!arqentrada) {
		cout << "Nao consegui abrir arquivo " << nomearq << endl;
		return 0;
	}
	//***************************//


	//*** Leitura do cabecalho ***//
	arqentrada >> tipo;		//Le o tipo de arquivo
	arqentrada.get();		//Le e descarta o \n do final da 1a. linha

	if (strcmp(tipo,"P2")==0) {
		cout << "Imagem em tons de cinza\n";
	}
	else if (strcmp(tipo,"P3")==0) {
		cout << "Imagem colorida\n";
		cout << "Desculpe, ainda nao trabalho com esse tipo de imagem.\n";
		arqentrada.close();
		return 0;
	}
	else if (strcmp(tipo,"P1")==0) {
		cout << "Imagem preto e branco\n";
		cout << "Desculpe, nao trabalho com esse tipo de imagem.\n";
		arqentrada.close();
		return 0;
	}
	else if (strcmp(tipo,"P4")==0 || strcmp(tipo,"P5")==0 || strcmp(tipo,"P6")==0) {
		cout << "Imagem no formato RAW\n";
		cout << "Desculpe, nao trabalho com esse tipo de imagem.\n";
		arqentrada.close();
		return 0;
	}

	while((c = arqentrada.get()) == '#')	//Enquanto for comentario
		arqentrada.getline(comentario,200);	//Le e descarta a linha "inteira"

	arqentrada.putback(c);					//Devolve o caractere lido para a entrada, pois como
											//nao era comentario, era o primeiro digito da largura

	arqentrada >> largura >> altura;		//Le as dimensoes da imagem, numero de pixels da horizontal e da vertical
	cout << "Tamanho: " << largura << " x " << altura << endl;
	if (largura>MAXLARGURA) {
		cout << "Desculpe, ainda nao trabalho com imagens com mais de " << MAXLARGURA << " pixels de largura.\n";
		arqentrada.close();
		return 0;
	}
	if (altura>MAXALTURA) {
		cout << "Desculpe, ainda nao trabalho com imagens com mais de " << MAXALTURA << " pixels de altura.\n";
		arqentrada.close();
		return 0;
	}

	arqentrada >> valor;	//Valor maximo do pixel (temos que ler, mas nao sera usado)
	//****************************//


	//*** Leitura dos pixels da imagem ***//
	for(i=0;i<altura;i++)
		for(j=0;j<largura;j++) {
			arqentrada >> valor;
			imagem[i][j] = (unsigned char)valor;
		}
	//************************************//

	arqentrada.close();  //Fecha arquivo apos a leitura

//*** FIM DA LEITURA DA IMAGEM ***//
	int processo;
	cout << "O que voce quer fazer com a imagem?" << endl;
	cout << "1-Escurecer" << endl;
	cout << "2-Clarear" << endl;
	cout << "3-Negativo" << endl;
	cout << "4-Inverter" << endl;
	cout << "5-Filtro de Sobel" << endl;
	cout << "6-Filtro de Realce" << endl;
	cin >> processo;

//*** TRATAMENTO DA IMAGEM ***//
//inicialmente sera nesta parte do codigo que voce vai trabalhar
	if (processo == 1){
		int fator;
		cout << "Qual o fator de escurecimento (1-100)? ";
		cin >> fator;
		//*** Escurece a imagem ***//
		for(i=0;i<altura;i++) {
			for(j=0;j<largura;j++) {
				valor = (int)imagem[i][j];						//pega o valor do pixel
				valor -= fator;									//escurece o pixel
				if (valor < 0)									//se der negativo
					valor = 0;									//  deixa preto
				imagem[i][j] = (unsigned char)valor;			//modifica o pixel
			}
		}
    //*************************//
	}
	if (processo == 2) {
		int fator;
		cout << "Qual o fator de clareamento (1-100)? ";
		cin >> fator;
	//*** clareia a imagem ***//
		for(i=0;i<altura;i++) {
			for(j=0;j<largura;j++) {
				valor = (int)imagem[i][j];						//pega o valor do pixel
				valor += fator;									//clareia o pixel
				if (valor > 255)								//se der maior que o max
					valor = 255;								//deixa 255
				imagem[i][j] = (unsigned char)valor;			//modifica o pixel
			}
    //*************************//
		}
	}
	if (processo == 3){
	//*** a imagem negativa ***//
		for(i=0;i<altura;i++) {
			for(j=0;j<largura;j++) {
				valor = 255 - (int)imagem[i][j];				//pega o valor do pixel e subtrai do total que e 255,
				imagem[i][j] = (unsigned char)valor;			//imprime na imagem o que falta no pixel para 255
    //*************************//
			}
		}
	}
	if (processo == 4){
		int imgAux[altura][largura];
		int k;
	//*** inverte a imagem ***//
		for(i=0;i<altura;i++) {
			k = largura-1;								//reseta k para o ultimo termo do vetor(larg - 1)(ultima coluna)
			for(j=0;j<largura;j++) {
				valor = (int)imagem[i][j];
				imgAux[i][k] = (unsigned char)valor;  	//cria um vetor auxiliar que recebe em sua ultima coordenada (coluna k) e na linha 0 o primeiro pixel da imagem
				k--;									//o segundo pixel no endereco [1][k-1], assim por diante				
			}
			for(j=0;j<largura;j++) {					//volta com o valor do pixel trocado de lugar na linha para o vetor imagem
				valor = (int)imgAux[i][j];
				imagem[i][j] = (unsigned char)valor;													
			}
		}
    //*************************//
	}
	if (processo == 5){
	//*** Filtro de sobel***//
		int imgAux[altura][largura];
		int k, valorMy, valorMx;
		int gy[3][3] = {{ 1,  2,  1},
						{ 0,  0,  0},
						{-1, -2, -1}};

		int gx[3][3] = {{ 1,  0, -1},
						{ 2,  0, -2},
						{ 1,  0, -1}};
			
		for(i=1;i<altura-1;i++) {
			for(j=1;j<largura-1;j++) {
				valorMy = gy[0][0] * imagem[i-1][j-1]+
				          gy[0][1] * imagem[i-1][j] +
						  gy[0][2] * imagem[i-1][j+1] +
						  gy[1][0] * imagem[i][j-1] +
						  gy[1][1] * imagem[i][j] +
						  gy[1][2] * imagem[i][j+1] +
						  gy[2][0] * imagem[i+1][j-1] +
						  gy[2][1] * imagem[i+1][j] +
						  gy[2][2] * imagem[i+1][j+1];
				
				valorMx = gx[0][0] * imagem[i-1][j-1]+
				          gx[0][1] * imagem[i-1][j] +
						  gx[0][2] * imagem[i-1][j+1] +
						  gx[1][0] * imagem[i][j-1] +
						  gx[1][1] * imagem[i][j] +
						  gx[1][2] * imagem[i][j+1] +
						  gx[2][0] * imagem[i+1][j-1] +
						  gx[2][1] * imagem[i+1][j] +
						  gx[2][2] * imagem[i+1][j+1];
				imgAux[i][j] = (int)sqrt(valorMy*valorMy+valorMx*valorMx);												
			}
		}
		for(i=0;i<altura-1;i++) {
			for(j=0;j<largura-1;j++) {
				valor = (int)imgAux[i][j];
				if (valor > 255){
					valor = 255;
				}
				if (valor < 0) {
					valor = 0;
				}
																		
				imagem[i][j] = (unsigned char)valor;			
			}
		}
    //*************************//
	}
	if (processo == 6){
	//*** Filtro de Realce***//
		int imgAux[altura][largura];
		int k, valorMy;
		int gy[3][3] = {{  0, -1,  0},
						{ -1,  5, -1},
						{  0, -1, 0}};
			
		for(i=1;i<altura-1;i++) {
			for(j=1;j<largura-1;j++) {
				valorMy = gy[0][0] * imagem[i-1][j-1]+
				          gy[0][1] * imagem[i-1][j] +
						  gy[0][2] * imagem[i-1][j+1] +
						  gy[1][0] * imagem[i][j-1] +
						  gy[1][1] * imagem[i][j] +
						  gy[1][2] * imagem[i][j+1] +
						  gy[2][0] * imagem[i+1][j-1] +
						  gy[2][1] * imagem[i+1][j] +
						  gy[2][2] * imagem[i+1][j+1];
				
				imgAux[i][j] = (int)valorMy;												
			}
		}
		for(i=0;i<altura-1;i++) {
			for(j=0;j<largura-1;j++) {
				valor = (int)imgAux[i][j];
				if (valor > 255){
					valor = 255;
				}
				if (valor < 0) {
					valor = 0;
				}
																		
				imagem[i][j] = (unsigned char)valor;			
			}
		}
    //*************************//
	}
//*** FIM DO TRATAMENTO DA IMAGEM ***//



//*** GRAVACAO DA IMAGEM ***//
//inicialmente nao sera necessario entender nem mudar nada nesta parte

	//*** Grava a nova imagem ***//
	string nomeNovaImg;
	cout << "Qual o nome voce quer dar para a nova imagem? (Nao e necessario escrever o formato .pnm)" << endl;
	cin >> nomeNovaImg;
	arqsaida.open( nomeNovaImg + ".pnm",ios::out);	//Abre arquivo para escrita
	if (!arqsaida) {
		cout << "Nao consegui criar novaimagem.pnm\n";
		return 0;
	}

	arqsaida << tipo << endl;				//tipo
	arqsaida << "# TP3-INF110, by AGS\n";	//comentario
	arqsaida << largura << " " << altura;	//dimensoes
	arqsaida << " " << 255 << endl;			//maior valor
	for(i=0;i<altura;i++)
		for(j=0;j<largura;j++)
			arqsaida << (int)imagem[i][j] << endl;	//pixels

	arqsaida.close();		//fecha o arquivo
	//***************************//

//*** FIM DA GRAVACAO DA IMAGEM ***//

	return 0;
}