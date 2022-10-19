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
	unsigned char imagemCol[MAXALTURA][MAXLARGURA][3];
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
	if (strcmp(tipo,"P3")==0){
		int k;
		for(i=0;i<altura;i++)
			for(j=0;j<largura;j++) {
				for(k=0;k<3;k++){
				arqentrada >> valor;
				imagemCol[i][j][k] = (unsigned char)valor;
				}
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
		cout << "7-Tons de cinza" << endl;
		cout << "8-Realcar tons especificos RGB" << endl;
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
					for(k=0;k<3;k++) {
					valor = (int)imagemCol[i][j][k];						//pega o valor do pixel
					valor -= fator;											//escurece o pixel
					if (valor < 0)											//se der negativo
						valor = 0;											//  deixa preto
					imagemCol[i][j][k] = (unsigned char)valor;				//modifica o pixel
					}
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
					for(k=0;k<3;k++) {
					valor = (int)imagemCol[i][j][k];					//pega o valor do pixel
					valor += fator;										//clareia o pixel
					if (valor > 255)									//se der maior que 255
						valor = 255;									//deixa branco
					imagemCol[i][j][k] = (unsigned char)valor;			//modifica o pixel
					}
				}
			}
		//*************************//
		}
		if (processo == 3){
		//*** a imagem negativa ***//
			for(i=0;i<altura;i++) {
				for(j=0;j<largura;j++) {
					for(k=0;k<3;k++) {
					valor = 255 - (int)imagemCol[i][j][k];				//pega o valor do pixel e subtrai do total que e 255,
					imagemCol[i][j][k] = (unsigned char)valor;			//imprime na imagem o que falta no pixel para 255
					}
		//*************************//
				}
			}
		}
		if (processo == 4){
			unsigned char imgAuxCol[altura][largura][3];				//cria uma matriz tridimensional auxiliar para receber os valores trocados da matriz original
			int k, l;
		//*** inverte a imagem ***//
			for(i=0;i<altura;i++) {
				l=largura-1;					// reseta o valor da ultima coluna na matriz auxiliar
				for(j=0;j<largura;j++) {								//atribui os primeiros pixels da linha da matriz original aos ultimos pixels da mesma linha da matriz
					for(k=0;k<3;k++) {									//auxiliar
						valor = (int)imagemCol[i][j][k];
						imgAuxCol[i][l][k] = (int)valor;
					}
					l--;	
				}
			}
			for(i=0;i<altura;i++) {
				for(j=0;j<largura;j++) {								//percorre a matriz auxiliar atribuindo os pixels espelhados para a imagem original
					for(k=0;k<3;k++) {				
						valor = (int)imgAuxCol[i][j][k];
						imagemCol[i][j][k] = (unsigned char)valor;
					}
				}
			}
		//*************************//
		}
		if (processo == 5){
		//*** Filtro de sobel***//
			unsigned char imgAuxCol[altura][largura][3];
			int k, valorMy, valorMx;
			int gy[3][3] = {{ 1,  2,  1},										//matriz do filtro para fazer as operações
							{ 0,  0,  0},
							{-1, -2, -1}};

			int gx[3][3] = {{ 1,  0, -1},
							{ 2,  0, -2},
							{ 1,  0, -1}};
				
			for(i=1;i<altura-1;i++) {
				for(j=1;j<largura-1;j++) {
					for(k=0;k<3;k++) {
						valorMy = gy[0][0] * imagemCol[i-1][j-1][k]+			//atribui ao valorMy o valor da conta de cada pixel
								gy[0][1] * imagemCol[i-1][j][k] +
								gy[0][2] * imagemCol[i-1][j+1][k] +
								gy[1][0] * imagemCol[i][j-1][k] +
								gy[1][1] * imagemCol[i][j][k] +
								gy[1][2] * imagemCol[i][j+1][k] +
								gy[2][0] * imagemCol[i+1][j-1][k] +
								gy[2][1] * imagemCol[i+1][j][k] +
								gy[2][2] * imagemCol[i+1][j+1][k];
						
						valorMx = gx[0][0] * imagemCol[i-1][j-1][k]+
								gx[0][1] * imagemCol[i-1][j][k] +
								gx[0][2] * imagemCol[i-1][j+1][k] +
								gx[1][0] * imagemCol[i][j-1][k] +
								gx[1][1] * imagemCol[i][j][k] +
								gx[1][2] * imagemCol[i][j+1][k] +
								gx[2][0] * imagemCol[i+1][j-1][k] +
								gx[2][1] * imagemCol[i+1][j][k] +
								gx[2][2] * imagemCol[i+1][j+1][k];
						valor = (int)(sqrt(valorMy * valorMy + valorMx * valorMx));   	//faz a operação para saber o valor final do pixel
						if (valor > 255){												//se o valor der maior que 255 ou negativo, se torna branco ou preto, respectivamente
							valor = 255;
						}
						if (valor < 0) {
							valor = 0;
						}
						imgAuxCol[i][j][k] = (unsigned char)valor;						//atribui o valor final ao pixel sobre o qual foi feito a conta				
					}
				}
			}
			for(i=0;i<altura-1;i++) {
				for(j=0;j<largura-1;j++) {												//percorre a matriz auxiliar atribuindo os pixels novos para a matriz original
					for(k=0;k<3;k++) {									
						imagemCol[i][j][k] = imgAuxCol[i][j][k];;			
					}
				}
			}
		//*************************//
		}
		if (processo == 6){
		//*** Filtro de Realce***//
			unsigned char imgAuxCol[altura][largura][3];		//realiza a operação de forma semelhante ao filtro de sobel com menos uma matriz para fazer as contas 
			int k, valorMy;
			int gy[3][3] = {{  0, -1,  0},
							{ -1,  5, -1},
							{  0, -1, 0}};
				
			for(i=1;i<altura-1;i++) {
				for(j=1;j<largura-1;j++) {
					for(k=0;k<3;k++) {
						valorMy = gy[0][0] * imagemCol[i-1][j-1][k]+
								gy[0][1] * imagemCol[i-1][j][k] +
								gy[0][2] * imagemCol[i-1][j+1][k] +
								gy[1][0] * imagemCol[i][j-1][k] +
								gy[1][1] * imagemCol[i][j][k] +
								gy[1][2] * imagemCol[i][j+1][k] +
								gy[2][0] * imagemCol[i+1][j-1][k] +
								gy[2][1] * imagemCol[i+1][j][k] +
								gy[2][2] * imagemCol[i+1][j+1][k];
						
						if (valorMy > 255){
							valorMy = 255;
						}
						if (valorMy < 0) {
							valorMy = 0;
						}
						imgAuxCol[i][j][k] = (unsigned char)valorMy;										
					}
				}
			}
			for(i=0;i<altura-1;i++) {
				for(j=0;j<largura-1;j++) {
					for(k=0;k<3;k++) {									
						imagemCol[i][j][k] = imgAuxCol[i][j][k];;			
					}
				}
			}
		}
		if (processo == 7){
		//*** Tons de Cinza ***//
			unsigned char imgAuxCol[altura][largura][3];
			int k;
			for(i=1;i<altura-1;i++) {
				for(j=1;j<largura-1;j++) {
					for(k=0;k<3;k++) {
						if(k==0){																				//faz a média aritmética das trincas de pixels RGB, para transformar as cores em tons de cinza
							valor = (int)(imagemCol[i][j][k] + imagemCol[i][j][k+1] + imagemCol[i][j][k+2])/3;
						}
						if(k==1){
							valor = (int)(imagemCol[i][j][k-1] + imagemCol[i][j][k] + imagemCol[i][j][k+1])/3;
						}
						if(k==2){
							valor = (int)(imagemCol[i][j][k-2] + imagemCol[i][j][k-1] + imagemCol[i][j][k])/3;
						}

						imgAuxCol[i][j][k] = (unsigned char)valor;										
					}
				}
			}
			for(i=0;i<altura-1;i++) {
				for(j=0;j<largura-1;j++) {
					for(k=0;k<3;k++) {									
						imagemCol[i][j][k] = imgAuxCol[i][j][k];;			
					}
				}
			}
		}
		if (processo == 8){
		//*** Realce de Tons Especificos RGB ***//
			unsigned char imgAuxCol[altura][largura][3];
			int k, sel, fator;	
			cout << "Qual cor voce quer realcar (1-Vermelho, 2-Verde, 3-Azul)" << endl;
			cin >> sel;
			cout << "Qual fator de realce? (1-100)" << endl;
			cin >> fator;
			for(i=1;i<altura-1;i++) {
				for(j=1;j<largura-1;j++) {				//ira percorrer a matriz e adicionar o fator de realce somente aonde as cores são dominantes
					for(k=0;k<3;k++) {
						if(k==0 && sel == 1 && imagemCol[i][j][0] > imagemCol[i][j][1] && imagemCol[i][j][0] > imagemCol[i][j][2]){																				//faz a média aritmética das trincas de pixels RGB, para transformar as cores em tons de cinza
							valor = fator + imagemCol[i][j][0];
						}
						else if(k==1 && sel == 2 && imagemCol[i][j][1] > imagemCol[i][j][0] && imagemCol[i][j][1] > imagemCol[i][j][2]){
							valor = fator + imagemCol[i][j][1];
						}
						else if(k==2 && sel == 3 && imagemCol[i][j][2] > imagemCol[i][j][1] && imagemCol[i][j][2] > imagemCol[i][j][1]){
							valor = fator + imagemCol[i][j][2];
						}
						else {
							valor = imagemCol[i][j][k];
						}
						if (valor > 255) {
							valor = 255;
						}

						imgAuxCol[i][j][k] = (unsigned char)valor;										
					}
				}
			}
			for(i=0;i<altura-1;i++) {
				for(j=0;j<largura-1;j++) {
					for(k=0;k<3;k++) {									
						imagemCol[i][j][k] = imgAuxCol[i][j][k];;			
					}
				}
			}
		}
	//*** FIM DO TRATAMENTO DA IMAGEM ***//



	//*** GRAVACAO DA IMAGEM ***//
	//inicialmente nao sera necessario entender nem mudar nada nesta parte

		//*** Grava a nova imagem ***//
		string nomeNovaImg;
		cout << "Qual o nome voce quer dar para a nova imagem? (Nao e necessario escrever o formato .pnm)" << endl;
		cin >> nomeNovaImg;
		arqsaida.open( nomeNovaImg +".pnm",ios::out);	//Abre arquivo para escrita
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
				for(k=0;k<3;k++)
				arqsaida << (int)imagemCol[i][j][k] << endl;	//pixels

		arqsaida.close();		//fecha o arquivo
		//***************************//

	//*** FIM DA GRAVACAO DA IMAGEM ***//
	}

	return 0;
}