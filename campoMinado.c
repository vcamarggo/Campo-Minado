#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10 //Tamanho máximo da matriz!

typedef struct Caixinha{
	int x;
	int y;
	struct Caixinha *prox;
}caixinha;

typedef struct Fila{
	struct Caixinha *inicioFila;
	struct Caixinha *fimFila;
}filinha;

int continuaJogo; //Inteiro que controla se o usuário ganhou o jogo
int fimJogo; // Inteiro que indica uma condição de fim de jogo
int tamMatriz;
int nBombas;
int x;
int y;
int solucao[MAX][MAX];
int controle[MAX][MAX];

//Verifica se o número de bombas não é igual ou maior que o numero de elementos da matriz
void num_de_bombas_valido(){
    int TamTotal;
    TamTotal = tamMatriz*tamMatriz;
    while(nBombas >= TamTotal || nBombas < 1){
        printf("\nNumero de bombas invalido!\n");
        printf("Insira outro valor: ");
        scanf("%i", &nBombas);
    }
}

//Preenche as matrizes com 0
void carrega_matriz(){
    for(int y=0; y<tamMatriz; y++){
        for(int x=0; x<tamMatriz; x++){
            solucao[x][y] = 0;
            controle[x][y] = 0;
        }
    }
}

//Coloca os números ao redor das bombas
void povoa_redor_bomba(int x, int y){
    if(x==0){
        if(y==0){
            if(solucao[x+1][y] != -1){
                solucao[x+1][y] ++;
            }
            if(solucao[x+1][y+1] != -1){
                solucao[x+1][y+1] ++;
            }
            if(solucao[x][y+1] != -1){
                solucao[x][y+1] ++;
            }
        }
        else if(y==(tamMatriz-1)){
                if(solucao[x+1][y] != -1){
                    solucao[x+1][y] ++;
                }
                if(solucao[x+1][y-1] != -1){
                    solucao[x+1][y-1] ++;
                }
                if(solucao[x][y-1] != -1){
                    solucao[x][y-1] ++;
                }
        }
        else{
            if(solucao[x][y-1] != -1){
                solucao[x][y-1] ++;
            }
            if(solucao[x][y+1] != -1){
                solucao[x][y+1] ++;
            }
            if(solucao[x+1][y-1] != -1){
                solucao[x+1][y-1] ++;
            }
            if(solucao[x+1][y] != -1){
                solucao[x+1][y] ++;
            }
            if(solucao[x+1][y+1] != -1){
                solucao[x+1][y+1] ++;
            }
        }
    }
    else if(y==0){
            if(x==(tamMatriz-1)){
                if(solucao[x-1][y] != -1){
                    solucao[x-1][y] ++;
                }
                if(solucao[x-1][y+1] != -1){
                    solucao[x-1][y+1] ++;
                }
                if(solucao[x][y+1] != -1){
                    solucao[x][y+1] ++;
                }
            }
            else{
                if(solucao[x+1][y] != -1){
                    solucao[x+1][y] ++;
                }
                if(solucao[x][y+1] != -1){
                    solucao[x][y+1] ++;
                }
                if(solucao[x+1][y+1] != -1){
                    solucao[x+1][y+1] ++;
                }
                if(solucao[x-1][y] != -1){
                    solucao[x-1][y] ++;
                }
                if(solucao[x-1][y+1] != -1){
                    solucao[x-1][y+1] ++;
                }
            }

    }
    else if(x==(tamMatriz-1)){
            if (y==(tamMatriz-1)){
                if(solucao[x-1][y] != -1){
                    solucao[x-1][y] ++;
                }
                if(solucao[x-1][y-1] != -1){
                    solucao[x-1][y-1] ++;
                }
                if(solucao[x][y-1] != -1){
                    solucao[x][y-1] ++;
                }
            }
            else{
                if(solucao[x][y-1] != -1){
                    solucao[x][y-1] ++;
                }
                if(solucao[x][y+1] != -1){
                    solucao[x][y+1] ++;
                }
                if(solucao[x-1][y-1] != -1){
                    solucao[x-1][y-1] ++;
                }
                if(solucao[x-1][y] != -1){
                    solucao[x-1][y] ++;
                }
                if(solucao[x-1][y+1] != -1){
                    solucao[x-1][y+1] ++;
                }
            }
    }
    else if(y==(tamMatriz-1)){
            if(solucao[x+1][y] != -1){
                solucao[x+1][y] ++;
            }
            if(solucao[x-1][y] != -1){
                solucao[x-1][y] ++;
            }
            if(solucao[x][y-1] != -1){
                solucao[x][y-1] ++;
            }
            if(solucao[x-1][y-1] != -1){
                solucao[x-1][y-1] ++;
            }
            if(solucao[x+1][y-1] != -1){
                solucao[x+1][y-1] ++;
            }
    }
    else{
            if(solucao[x][y-1] != -1){
                solucao[x][y-1] ++;
            }
            if(solucao[x][y+1] != -1){
                solucao[x][y+1] ++;
            }
            if(solucao[x-1][y] != -1){
                solucao[x-1][y] ++;
            }
            if(solucao[x+1][y] != -1){
                solucao[x+1][y] ++;
            }
            if(solucao[x+1][y+1] != -1){
                solucao[x+1][y+1] ++;
            }
            if(solucao[x+1][y-1] != -1){
                solucao[x+1][y-1] ++;
            }
            if(solucao[x-1][y-1] != -1){
                solucao[x-1][y-1] ++;
            }
            if(solucao[x-1][y+1] != -1){
                solucao[x-1][y+1] ++;
            }
    }
}

//Escolhe o lugar das bombas aleatoriamente
void coloca_bomba(){
    int i,j,contaBomba=0;
    while (contaBomba<nBombas){
        srand( (unsigned)time(NULL) );
        i=rand()%tamMatriz;
        j=rand()%tamMatriz;
        if (solucao[i][j] !=-1){
            solucao[i][j] =-1;
            povoa_redor_bomba(i, j);
            contaBomba+=1;
        }
    }
}

//Mostra a matriz solução a cada rodada
void imprime_matriz(){
    int a,b,k;
    printf("\n");
    printf(" ");
    for(k=0; k<tamMatriz+1; k++){
        printf("%i  ", k);
    }
    printf("\n");
    for(a=0; a<tamMatriz; a++){
        for(b=0; b<tamMatriz; b++){
            if(b==0){
                printf(" %i ", a+1);
            }
            if(controle[a][b] == 0){
                printf(" X ");
            }
            if(controle[a][b] == 1){
                if(solucao[a][b] != -1)
                    printf(" %i " ,solucao[a][b]);
                else
                    printf(" B ");
            }
            if(controle[a][b] == 2){
                printf(" M ");
            }
        }
        printf("\n");
    }

}

//Fila Vazia
int vazia(filinha *fila){
	if(fila->inicioFila == NULL)
		return 1;
	else
		return 0;
}

//Nova Caixinha
caixinha *criaCaixinha(){
	caixinha *novo=(caixinha *) malloc(sizeof(caixinha));
		return novo;
}

//Remove Fila
filinha *removeFila(filinha *fila){
    fila->inicioFila = fila->inicioFila->prox;
    if(vazia(fila) == 1){
        fila->fimFila= NULL;
    }
    return fila;
}

//Insere Fila
filinha *insere(int x, int y, filinha *fila){
	caixinha *aux = criaCaixinha();
	aux->x = x;
	aux->y = y;
	aux->prox =NULL;
	if(vazia(fila)){
		fila->inicioFila = aux;
	}
	else{
        fila->fimFila->prox = aux;
	}
	fila->fimFila = aux;
	aux = NULL;
	free(aux);
	return fila;
}

//Verifica vizinhos do zero
filinha *olhaVizinhos(int i, int j, filinha *fila){
    if(i >= 0 && i <= tamMatriz-1 && j>= 0 && j <= tamMatriz-1){
        if((controle[i-1][j] ==0 )&&( solucao[i-1][j] == 0)){
            controle[i-1][j] = 1;
            fila = insere(i-1, j,fila);
        }
        else{
            if(i > 0)
                controle[i-1][j] = 1;
        }
        if((controle[i+1][j] ==0 )&&( solucao[i+1][j] == 0)){
            controle[i+1][j] = 1;
            fila = insere(i+1, j, fila);
        }
        else{
            if(i < tamMatriz)
                controle[i+1][j] = 1;
        }
        if((controle[i][j+1] ==0 )&&( solucao[i][j+1] == 0)){
            controle[i][j+1] = 1;
            fila = insere(i, j+1,fila);
        }
        else{
            if(j < tamMatriz)
                controle[i][j+1] = 1;
        }
        if((controle[i+1][j+1] ==0 )&&( solucao[i+1][j+1] == 0)){
            controle[i+1][j+1] = 1;
            fila = insere(i+1, j+1,fila);
        }
        else{
            if(i < tamMatriz && j < tamMatriz)
                controle[i+1][j+1] = 1;
        }
        if((controle[i-1][j+1] ==0 )&&( solucao[i-1][j+1] == 0)){
            controle[i-1][j+1] = 1;
            fila = insere(i-1, j+1,fila);
        }
        else{
            if(i > 0 && j < tamMatriz)
                controle[i-1][j+1] = 1;
        }
        if((controle[i][j-1] ==0 )&&( solucao[i][j-1] == 0)){
            controle[i][j-1] = 1;
            fila = insere(i, j-1,fila);
        }
        else{
            if(j > 0)
                controle[i][j-1] = 1;
        }
        if((controle[i+1][j-1] ==0 )&&( solucao[i+1][j-1] == 0)){
            controle[i+1][j-1] = 1;
            fila = insere(i+1, j-1,fila);
        }
        else{
            if(i > 0)
                controle[i+1][j-1] = 1;
        }
        if((controle[i-1][j-1] ==0 )&&( solucao[i-1][j-1] == 0)){
            controle[i-1][j-1] = 1;
            fila = insere(i-1, j-1,fila);
        }
        else{
            if(i > 0 && j > 0)
                controle[i-1][j-1] = 1;
        }
    }
    return fila;
}

//Função que controla os elementos da fila
void explodeZeros(int x,int y,filinha *fila){
    int i, j;
      caixinha *caixinha = criaCaixinha();
      caixinha->x = x;
      caixinha->y = y;
      caixinha->prox =NULL;
      fila->inicioFila = caixinha;
      fila->fimFila = caixinha;
      while(vazia(fila) == 0){
            i = fila->inicioFila->x;
            j = fila->inicioFila->y;
            fila = removeFila(fila); //remove primeiro pois esta coordenada já recebeu valor 1 no controlaMatriz
            fila = olhaVizinhos(i, j, fila);
      }
}

//Decide se continua o jogo ou encerra, supondo inicialmente que o jogador esta ganhando
void verificaGanhou(){
	int x, y;
    fimJogo = 0;
    continuaJogo = -2;
    for(x=0; x<tamMatriz; x++){
        for(y=0; y<tamMatriz; y++){
            if(controle[x][y] != 1 && solucao[x][y] != -1) {
                fimJogo = 1;
                continuaJogo = 0;
            }
        }
    }
}

//Faz o controle dos elementos do jogo
void controlaMatriz(int x, int y, filinha *fila){
	if(controle[x][y] != 1){
		controle[x][y] = 1;
		if(solucao[x][y] == 0){
			fila->inicioFila = NULL;
			fila->fimFila = fila->inicioFila;
			explodeZeros(x, y, fila);
		}
		if(solucao[x][y] == -1){
			fimJogo = 0;
			continuaJogo = -1;
		}
		else{
			verificaGanhou();
		}
	}
	else
        printf("Coordenada ja inserida!\n\n");
}

//Marca posição da bomba escolhida pelo usuário
void marca_bomba(){
        int soma=0;
        imprime_matriz();
        for(int i=0;i<tamMatriz;i++){
            for(int j=0;j<tamMatriz;j++){
                if(controle[i][j] == 2){
                    soma ++;
                }
            }
        }
        printf("\nInsira uma coordenada X,Y nos intervalos X[1-%i],Y[1-%i] (Separados por virgula)\n", tamMatriz, tamMatriz);
        scanf("%i,%i", &x, &y);
        system("cls");
        if(controle[x-1][y-1] == 0 && soma < nBombas){
            controle[x-1][y-1] = 2;
        }
        else if(controle[x-1][y-1] == 2){
            controle[x-1][y-1] = 0;
        }
        else if(controle[x-1][y-1] == 1){
            printf("\nCoordenada ja aberta!\n");
        }
        else{
            printf("\nNumero de marcacoes max atingido!");
        }
        imprime_matriz();
}

int main(){
    char continua;
    char opcao;
    do{
        printf(" *****CAMPO MINADO*****\n\n");
        printf("Digite o Tamanho do Campo (2 a %i): ", MAX);
        scanf("%i", &tamMatriz);
        if(tamMatriz<2 || tamMatriz>MAX){
            do{
                printf("Insira um Tamanho Valido!: ");
                scanf("%i", &tamMatriz);
            }while(tamMatriz<2 || tamMatriz>MAX);
        }
        printf("Digite o Numero de Bombas: ");
        scanf("%i", &nBombas);
        num_de_bombas_valido();
        carrega_matriz();
        coloca_bomba();
        system("cls");
        printf("\n");
        filinha *fila = (filinha *)  malloc(sizeof(filinha));
        do{
            printf("\nSelecione a opcao:\n");
            printf("A - Abrir Quadrado \n");
            printf("M - Marcar/Desmarcar Bomba \n");
            scanf("%s", &opcao);
            if(opcao == 'A' || opcao == 'a'){
                system("cls");
                imprime_matriz();
                printf("\nInsira uma coordenada X,Y nos intervalos X[1-%i],Y[1-%i] (Separados por virgula)\n", tamMatriz, tamMatriz);
                scanf("%i,%i", &x, &y);
                controlaMatriz(x-1, y-1, fila);
                system("cls");
                imprime_matriz();
            }
            else if(opcao == 'M' || opcao == 'm'){
                system("cls");
                marca_bomba();
                fimJogo = 1;
            }
            else{
                printf("Opcao Invalida!!!!!\n");
                fimJogo = 1;
            }
        }while(fimJogo);

         //Executa apenas quando termina o jogo
        if(continuaJogo == -1){
            printf("Voce Perdeu! \n");
            printf("Deseja continuar jogando? \n");
            printf("1 - SIM \n");
            printf("0 - NAO \n");
            scanf("%s",&continua);
            system("cls");
        }
        if(continuaJogo == -2){
            printf("Voce Ganhou! \n");
            printf("Deseja continuar jogando? \n");
            printf("1 - SIM \n");
            printf("0 - NAO \n");
            scanf("%s",&continua);
            system("cls");
        }
    }while(continua == '1');
}






