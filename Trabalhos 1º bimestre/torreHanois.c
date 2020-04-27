#include <stdio.h>
#include<stdlib.h>
#include "pilha1.h"
#include <locale.h>

void menuPrincipal(pilha *pino1, pilha *pino2, pilha *pino3);
void insereDiscos(pilha *pino1);
int vencedor(pilha *pino3);
int moverDisco(pilha *pino1, pilha *pino2,pilha *pino3);
int MenuJogadas ();
int verificaMovimento(pilha *qualPino, pilha *paraQual);

int vencedor(pilha *pino3){
	if(pino3->vet[3] == 1){
		system("color 2");
		printf("VOCE VENCEEEEEEU!!\n");
		exibePilha(pino3,3);
		return 1;
	}
	else
		return 0;
}
void menuPrincipal(pilha *pino1, pilha *pino2, pilha *pino3){
	int opcao = 0, movimentos = 25;
	vencedor(pino3);
	while(((opcao != 3)&&(movimentos >= 1))||(vencedor(pino3) == 1)){

		printf("O que deseja fazer ?\nDigite:\n(1)- Mover um disco\n(2)-Exibir pinos\n(3)-Sair\n(4)-Visualizar objetivo do jogo e as regras\n");
		scanf("%d",&opcao);
		system("pause");
		system("cls");
		printf("Voce ainda tem %d movimentos\n",movimentos);
		switch(opcao){
			case 1:
			if(moverDisco(pino1,pino2,pino3) == 1){
				movimentos--;
				printf("Movimento realizado com sucesso\n");
			}
			else
				printf("Nao foi possivel realizar o movimento(veja as regras do jogo se necessario)\n");
			break;
			case 2:
			printf("Estes sao os seus pinos:\n-->\n\n");
			exibePilha(pino1,1);
			exibePilha(pino2,2);
			exibePilha(pino3,3);
			break;
			case 3:
			break;
			case 4:
			printf("\n\n\n______________________________________OBJETIVO_____________________________________________________________: \nTransferir todos o discos do pino 1 para o pino 3.\n Eles devem estar na ordem 4 - 3 - 2 - 1\n\n");
			printf("Regras:\n\n1º- Voce nao pode passar um disco de diametro maior para um pino, se nesse pino ha um disco de diametro menor;\n\n");
			printf("2º-Voce nao deve exceder o limite de jogadas;\n\n");
			printf("3º-Voce nao consegue remover um disco de um pino vazio(Nem faz sentido tentar,né !?).\n");
			printf("_______________________________________________________________________________________________________________\n");
			system("pause");

			system("cls");
			break;
		}
	}
}
int moverDisco(pilha *pino1, pilha *pino2,pilha *pino3){
	int opcao, verificador;
	opcao = MenuJogadas();

	switch(opcao){

	case 1 :
		verificador = verificaMovimento(pino1, pino2);
	break;
	case 2 :
		verificador = verificaMovimento(pino1, pino3);
	break;
	case 3 :
		verificador = verificaMovimento(pino2, pino1);
	break;
	case 4 : 
		verificador = verificaMovimento(pino2, pino3);
	break;
	case 5 :
	 verificador = verificaMovimento(pino3, pino1);
	break;
	case 6 :
	verificador = verificaMovimento(pino3, pino2);
	break;
	}
	return verificador;
}
int MenuJogadas (){
	int opcao;
	
	printf("..........................................................\n");
	printf("DIGITE O NUMERO REFERENTE A OPERACAO QUE DESEJA REALIZAR\n\n\n");
	printf("(1)- Do pino 1 para  o pino 2 \n\n");
	printf("(2)- Do pino 1 para  o pino 3 \n\n");
	printf("(3)- Do pino 2 para  o pino 1\n\n");
	printf("(4)- Do pino 2  para o pino 3 \n\n");
	printf("(5)- Do pino 3 para  o pino 1 \n\n");
	printf("(6)- Do pino 3 para  o pino 2 \n\n");
	printf(".........................................................\n");
	scanf("%d",&opcao);
	return opcao;
}
int verificaMovimento(pilha *qualPino, pilha *paraQual){
	if(paraQual-> topo == 0){
		push(paraQual, pop(qualPino));
		return 1;
	}
	if(((qualPino->vet[qualPino->topo] < paraQual->vet[paraQual->topo - 1]) && 
        (cheiaPilha(paraQual) == 0) && (vaziaPilha(qualPino) == 0))){
		push(paraQual, pop(qualPino));
		return 1;
	}
	else
		return 0;
}
void insereDiscos(pilha *pino1){
	push(pino1,4);
	push(pino1,3);
	push(pino1,2);
	push(pino1,1);

}
int main(){
	pilha pino1, pino2, pino3;
	 setlocale(LC_ALL, "Portuguese");

	iniciaPilha(&pino1);
	iniciaPilha(&pino2);
	iniciaPilha(&pino3);

	insereDiscos(&pino1);
	
	menuPrincipal(&pino1,&pino2,&pino3);
	if(vencedor(&pino3) == 0)
		printf("Voce perdeu. :( \n");


}